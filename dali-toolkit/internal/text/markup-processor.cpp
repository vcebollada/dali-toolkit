/*
 * Copyright (c) 2015 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

// FILE HEADER
#include <dali-toolkit/internal/text/markup-processor.h>

// INTERNAL INCLUDES
#include <dali-toolkit/internal/text/character-set-conversion.h>
#include <dali-toolkit/internal/text/markup-processor-helper-functions.h>

namespace Dali
{

namespace Toolkit
{

namespace Text
{

namespace
{
// HTML-ISH tag and attribute constants.
// Note they must be lower case in order to make the comparison to work
// as the parser converts all the read tags to lower case.
const std::string XHTML_COLOR_TAG("color");
const std::string XHTML_FONT_TAG("font");
const std::string XHTML_B_TAG("b");
const std::string XHTML_I_TAG("i");
const std::string XHTML_U_TAG("u");
const std::string XHTML_SHADOW_TAG("shadow");
const std::string XHTML_GLOW_TAG("glow");
const std::string XHTML_OUTLINE_TAG("outline");

const char LESS_THAN         = '<';
const char GREATER_THAN      = '>';
const char EQUAL             = '=';
const char QUOTATION_MARK    = '\'';
const char LINE_SEPARATOR_CR = 0x0D; // Carriage return character  CR
const char LINE_SEPARATOR_LF = 0x0A; // New line character         LF
const char SLASH             = '/';
const char BACK_SLASH        = '\\';

const char WHITE_SPACE       = 0x20; // ASCII value of the white space.

const unsigned int MAX_NUM_OF_ATTRIBUTES =  5u; ///< The font tag has the 'family', 'size' 'weight', 'width' and 'slant' attrubutes.

/**
 * @brief Splits the tag string into the tag name and its attributes.
 *
 * The attributes are stored in a vector in the tag.
 *
 * @param[in,out] tag The tag.
 */
void ParseAttributes( Tag& tag )
{
  tag.attributes.Resize( MAX_NUM_OF_ATTRIBUTES );

  // Find first the tag name.
  bool isQuotationOpen = false;

  const char* tagBuffer = tag.buffer;
  const char* const tagEndBuffer = tagBuffer + tag.length;
  tag.length = 0u;
  for( ; tagBuffer < tagEndBuffer; ++tagBuffer )
  {
    const char character = *tagBuffer;
    if( WHITE_SPACE < character )
    {
      ++tag.length;
    }
    else
    {
      // Stops counting the length of the tag when a white space is found.
      // @note a white space is the WHITE_SPACE character and anything below as 'tab', 'return' or 'control characters'.
      break;
    }
  }
  SkipWhiteSpace( tagBuffer, tagEndBuffer );

  // Find the attributes.
  unsigned int attributeIndex = 0u;
  const char* nameBuffer = NULL;
  const char* valueBuffer = NULL;
  Length nameLength = 0u;
  Length valueLength = 0u;

  bool addToNameValue = true;
  Length numberOfWhiteSpace = 0u;
  for( ; tagBuffer < tagEndBuffer; ++tagBuffer )
  {
    const char character = *tagBuffer;
    if( ( WHITE_SPACE >= character ) && !isQuotationOpen )
    {
      if( NULL != valueBuffer )
      {
        // Remove white spaces at the end of the value.
        valueLength -= numberOfWhiteSpace;
      }

      if( ( NULL != nameBuffer ) && ( NULL != valueBuffer ) )
      {
        // Every time a white space is found, a new attribute is created and stored in the attributes vector.
        Attribute& attribute = *( tag.attributes.Begin() + attributeIndex );
        ++attributeIndex;

        attribute.nameBuffer = nameBuffer;
        attribute.valueBuffer = valueBuffer;
        attribute.nameLength = nameLength;
        attribute.valueLength = valueLength;

        nameBuffer = NULL;
        valueBuffer = NULL;
        nameLength = 0u;
        valueLength = 0u;

        addToNameValue = true; // next read characters will be added to the name.
      }
    }
    else if( EQUAL == character ) // '='
    {
      addToNameValue = false; // next read characters will be added to the value.
      SkipWhiteSpace( tagBuffer, tagEndBuffer );
    }
    else if( QUOTATION_MARK == character ) // '\''
    {
      // Do not add quotation marks to neither name nor value.
      isQuotationOpen = !isQuotationOpen;

      if( isQuotationOpen )
      {
        ++tagBuffer;
        SkipWhiteSpace( tagBuffer, tagEndBuffer );
        --tagBuffer;
      }
    }
    else
    {
      // Adds characters to the name or the value.
      if( addToNameValue )
      {
        if( NULL == nameBuffer )
        {
          nameBuffer = tagBuffer;
        }
        ++nameLength;
      }
      else
      {
        if( isQuotationOpen )
        {
          if( WHITE_SPACE >= character )
          {
            ++numberOfWhiteSpace;
          }
          else
          {
            numberOfWhiteSpace = 0u;
          }
        }
        if( NULL == valueBuffer )
        {
          valueBuffer = tagBuffer;
        }
        ++valueLength;
      }
    }
  }

  if( NULL != valueBuffer )
  {
    // Remove white spaces at the end of the value.
    valueLength -= numberOfWhiteSpace;
  }

  if( ( NULL != nameBuffer ) && ( NULL != valueBuffer ) )
  {
    // Checks if the last attribute needs to be added.
    Attribute& attribute = *( tag.attributes.Begin() + attributeIndex );
    ++attributeIndex;

    attribute.nameBuffer = nameBuffer;
    attribute.valueBuffer = valueBuffer;
    attribute.nameLength = nameLength;
    attribute.valueLength = valueLength;
  }

  // Resize the vector of attributes.
  tag.attributes.Resize( attributeIndex );
}

/**
 * @brief It parses a tag and its attributes if the given iterator @e it is pointing at a tag beginning.
 *
 * @param[in,out] markupStringBuffer The mark-up string buffer. It's a const iterator pointing the current character.
 * @param[in] markupStringEndBuffer Pointer to one character after the end of the mark-up string buffer.
 * @param[out] tag The tag with its attributes.
 *
 * @return @e true if the iterator @e it is pointing a mark-up tag. Otherwise @e false.
 */
bool IsTag( const char*& markupStringBuffer,
            const char* const markupStringEndBuffer,
            Tag& tag )
{
  bool isTag = false;
  bool isQuotationOpen = false;
  bool attributesFound = false;
  tag.isEndTag = false;

  const char character = *markupStringBuffer;
  if( LESS_THAN == character ) // '<'
  {
    tag.buffer = NULL;
    tag.length = 0u;

    // if the iterator is pointing to a '<' character, then check if it's a mark-up tag is needed.
    ++markupStringBuffer;
    if( markupStringBuffer < markupStringEndBuffer )
    {
      SkipWhiteSpace( markupStringBuffer, markupStringEndBuffer );

      for( ; ( !isTag ) && ( markupStringBuffer < markupStringEndBuffer ); ++markupStringBuffer )
      {
        const char character = *markupStringBuffer;

        if( SLASH == character ) // '/'
        {
          // if the tag has a '/' then it's an end or empty tag.
          tag.isEndTag = true;

          if( ( markupStringBuffer + 1u < markupStringEndBuffer ) && ( WHITE_SPACE >= *( markupStringBuffer + 1u ) ) && ( !isQuotationOpen ) )
          {
            ++markupStringBuffer;
            SkipWhiteSpace( markupStringBuffer, markupStringEndBuffer );
            --markupStringBuffer;
          }
        }
        else if( GREATER_THAN == character ) // '>'
        {
          isTag = true;
        }
        else if( QUOTATION_MARK == character )
        {
          isQuotationOpen = !isQuotationOpen;
          ++tag.length;
        }
        else if( WHITE_SPACE >= character ) // ' '
        {
          // If the tag contains white spaces then it may have attributes.
          if( !isQuotationOpen )
          {
            attributesFound = true;
          }
          ++tag.length;
        }
        else
        {
          if( NULL == tag.buffer )
          {
            tag.buffer = markupStringBuffer;
          }

          // If it's not any of the 'special' characters then just add it to the tag string.
          ++tag.length;
        }
      }
    }

    // If the tag string has white spaces, then parse the attributes is needed.
    if( attributesFound )
    {
      ParseAttributes( tag );
    }
  }

  return isTag;
}

} // namespace

void ProcessMarkupString( const std::string& markupString, MarkupProcessData& markupProcessData )
{
  // Reserve space for the plain text.
  const Length markupStringSize = markupString.size();
  markupProcessData.markupProcessedText.reserve( markupStringSize );

  // Get the mark-up string buffer.
  const char* markupStringBuffer = markupString.c_str();
  const char* const markupStringEndBuffer = markupStringBuffer + markupStringSize;

  Tag tag;
  CharacterIndex characterIndex = 0u;
  for( ; markupStringBuffer < markupStringEndBuffer; )
  {
    if( IsTag( markupStringBuffer,
               markupStringEndBuffer,
               tag ) )
    {
      if( TokenComparison( XHTML_COLOR_TAG, tag.buffer, tag.length ) )
      {
        if( !tag.isEndTag )
        {
          // Create a new color run.
        }
        else
        {
          // Pop the top of the stack and set the number of characters of the run.
        }
      } // <color></color>
      else if( TokenComparison( XHTML_I_TAG, tag.buffer, tag.length ) )
      {
        if( !tag.isEndTag )
        {
          // Create a new font run.
        }
        else
        {
          // Pop the top of the stack and set the number of characters of the run.
        }
      } // <i></i>
      else if( TokenComparison( XHTML_U_TAG, tag.buffer, tag.length ) )
      {
        if( !tag.isEndTag )
        {
          // Create a new underline run.
        }
        else
        {
          // Pop the top of the stack and set the number of characters of the run.
        }
      } // <u></u>
      else if( TokenComparison( XHTML_B_TAG, tag.buffer, tag.length ) )
      {
        if( !tag.isEndTag )
        {
          // Create a new font run.
        }
        else
        {
          // Pop the top of the stack and set the number of characters of the run.
        }
      } // <b></b>
      else if( TokenComparison( XHTML_FONT_TAG, tag.buffer, tag.length ) )
      {
        if( !tag.isEndTag )
        {
          // Create a new font run.
        }
        else
        {
          // Pop the top of the stack and set the number of characters of the run.
        }
      } // <font></font>
      else if( TokenComparison( XHTML_SHADOW_TAG, tag.buffer, tag.length ) )
      {
        if( !tag.isEndTag )
        {
          // Create a new shadow run.
        }
        else
        {
          // Pop the top of the stack and set the number of characters of the run.
        }
      } // <shadow></shadow>
      else if( TokenComparison( XHTML_GLOW_TAG, tag.buffer, tag.length ) )
      {
        if( !tag.isEndTag )
        {
          // Create a new glow run.
        }
        else
        {
          // Pop the top of the stack and set the number of characters of the run.
        }
      } // <glow></glow>
      else if( TokenComparison( XHTML_OUTLINE_TAG, tag.buffer, tag.length ) )
      {
        if( !tag.isEndTag )
        {
          // Create a new outline run.
        }
        else
        {
          // Pop the top of the stack and set the number of characters of the run.
        }
      } // <outline></outline>
    }  // end if( IsTag() )
    else
    {
      unsigned char character = *markupStringBuffer;

      if( ( BACK_SLASH == character ) && ( markupStringBuffer + 1u < markupStringEndBuffer ) )
      {
        // Adding < or > special character.
        const unsigned char nextCharacter = *( markupStringBuffer + 1u );
        if( ( LESS_THAN == nextCharacter ) || ( GREATER_THAN == nextCharacter ) )
        {
          character = nextCharacter;
          ++markupStringBuffer;
        }
      }
      else if( ( LINE_SEPARATOR_CR == character ) && ( markupStringBuffer + 1u < markupStringEndBuffer ) )
      {
        // Replacing CR+LF end line by LF.
        if( LINE_SEPARATOR_LF == *( markupStringBuffer + 1u ) )
        {
          character = LINE_SEPARATOR_LF;
          ++markupStringBuffer;
        }
      }

      const unsigned char numberOfBytes = GetUtf8Length( character );

      markupProcessData.markupProcessedText.push_back( character );
      for( unsigned char i = 1u; i < numberOfBytes; ++i )
      {
        ++markupStringBuffer;
        markupProcessData.markupProcessedText.push_back( *markupStringBuffer );
      }

      ++characterIndex;
      ++markupStringBuffer;
    }
  }

  // Resize the model's vectors.
}

} // namespace Text

} // namespace Toolkit

} // namespace Dali
