/*
 * Copyright (c) 2016 Samsung Electronics Co., Ltd.
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

#include <dali-toolkit-test-suite-utils.h>
#include <dali-toolkit/devel-api/visual-factory/visual-factory.h>
#include <dali/public-api/rendering/renderer.h>
#include <dali/public-api/rendering/geometry.h>

#include <toolkit-environment-variable.h> // for setting environment variable: DALI_DEBUG_RENDERING

using namespace Dali;
using namespace Dali::Toolkit;

namespace
{
const char* TEST_IMAGE_FILE_NAME =  "image_01.jpg";
const char* TEST_NPATCH_FILE_NAME =  "image_01.9.jpg";

bool IsDebugVisual( Visual::Base& visual )
{
  bool isDebugVisualType = false;
  bool isGeometryLineType = false;

  Property::Map propertyMap;
  visual.CreatePropertyMap( propertyMap );
  Property::Value* typeValue = propertyMap.Find( "rendererType",  Property::STRING );
  if ( typeValue )
  {
    isDebugVisualType = ( typeValue->Get<std::string>() == "DEBUG" );
  }

  Actor actor = Actor::New();
  visual.SetOnStage( actor );
  Geometry geometry = actor.GetRendererAt( 0 ).GetGeometry();
  isGeometryLineType = ( geometry.GetGeometryType() == Geometry::LINES );

  return isDebugVisualType && isGeometryLineType;
}
}

void dali_debug_renderer_startup(void)
{
  test_return_value = TET_UNDEF;
}

void dali_debug_renderer_cleanup(void)
{
  test_return_value = TET_PASS;
}

int UtcDaliDebugVisualGetVisual1(void)
{
  EnvironmentVariable::SetTestingEnvironmentVariable(true);
  ToolkitTestApplication application;
  tet_infoline( "UtcDaliDebugVisualGetVisual1:  Request visual with a Property::Map" );

  VisualFactory factory = VisualFactory::Get();
  DALI_TEST_CHECK( factory );

  // Test that color visual is replaced with debug visual
  Property::Map propertyMap1;
  propertyMap1.Insert("rendererType",  "COLOR");
  propertyMap1.Insert("mixColor",  Color::BLUE);
  Visual::Base colorVisual = factory.CreateVisual(propertyMap1);
  DALI_TEST_CHECK( colorVisual );
  DALI_TEST_CHECK( IsDebugVisual( colorVisual ) );

  // Test that border visual is replaced with debug visual
  Property::Map propertyMap2;
  propertyMap2.Insert("rendererType",  "BORDER");
  propertyMap2.Insert("borderColor",  Color::BLUE);
  propertyMap2.Insert("borderSize",  2.f);
  Visual::Base borderVisual = factory.CreateVisual(propertyMap2);
  DALI_TEST_CHECK( borderVisual );
  DALI_TEST_CHECK( IsDebugVisual( borderVisual ) );

  // Test that gradient visual is replaced with debug visual
  Property::Map propertyMap3;
  propertyMap3.Insert("rendererType",  "GRADIENT");
  Vector2 start(-1.f, -1.f);
  Vector2 end(1.f, 1.f);
  propertyMap3.Insert("startPosition", start);
  propertyMap3.Insert("endPosition", end);
  propertyMap3.Insert("spreadMethod", "REPEAT");
  Property::Array stopOffsets;
  stopOffsets.PushBack( 0.2f );
  stopOffsets.PushBack( 0.8f );
  propertyMap3.Insert("stopOffset", stopOffsets);
  Property::Array stopColors;
  stopColors.PushBack( Color::RED );
  stopColors.PushBack( Color::GREEN );
  propertyMap3.Insert("stopColor", stopColors);
  Visual::Base gradientVisual = factory.CreateVisual(propertyMap3);
  DALI_TEST_CHECK( gradientVisual );
  DALI_TEST_CHECK( IsDebugVisual( gradientVisual ) );

  // Test that image visual is replaced with debug visual
  Property::Map propertyMap4;
  propertyMap4.Insert( "rendererType",  "IMAGE" );
  propertyMap4.Insert( "url",  TEST_IMAGE_FILE_NAME );
  Visual::Base imageVisual = factory.CreateVisual( propertyMap4 );
  DALI_TEST_CHECK( imageVisual );
  DALI_TEST_CHECK( IsDebugVisual( imageVisual ) );

  // Test that n patch visual is replaced with debug visual
  Property::Map propertyMap5;
  propertyMap5.Insert( "rendererType",  "IMAGE" );
  propertyMap5.Insert( "url",  TEST_NPATCH_FILE_NAME );
  Visual::Base nPatchVisual = factory.CreateVisual( propertyMap4 );
  DALI_TEST_CHECK( nPatchVisual );
  DALI_TEST_CHECK( IsDebugVisual( nPatchVisual ) );

  EnvironmentVariable::SetTestingEnvironmentVariable(false);
  END_TEST;
}

int UtcDaliDebugVisualGetVisual2(void)
{
  EnvironmentVariable::SetTestingEnvironmentVariable(true);
  ToolkitTestApplication application;
  tet_infoline( "UtcDaliDebugVisualGetVisual2: Request visual with various parameters" );

  VisualFactory factory = VisualFactory::Get();
  DALI_TEST_CHECK( factory );

  // Test that color visual is replaced with debug visual
  Dali::Property::Map map;
  map[ "rendererType" ] = "COLOR";
  map[ "mixColor" ] = Color::CYAN;

  Visual::Base colorVisual = factory.CreateVisual( map);
  DALI_TEST_CHECK( colorVisual );
  DALI_TEST_CHECK( IsDebugVisual( colorVisual ) );

  // Test that border visual is replaced with debug visual
  map.Clear();
  map[ "rendererType" ] = "BORDER";
  map[ "borderColor"  ] = Color::GREEN;
  map[ "borderSize"   ] = 2.f;
  Visual::Base borderVisual = factory.CreateVisual( map );
  DALI_TEST_CHECK( borderVisual );
  DALI_TEST_CHECK( IsDebugVisual( borderVisual ) );

  // Test that image visual is replaced with debug visual
  Image image = ResourceImage::New(TEST_IMAGE_FILE_NAME);
  Visual::Base imageVisual = factory.CreateVisual( image );
  DALI_TEST_CHECK( imageVisual );
  DALI_TEST_CHECK( IsDebugVisual( imageVisual ) );

  // Test that n patch visual is replaced with debug visual
  Visual::Base nPatchVisual = factory.CreateVisual( TEST_NPATCH_FILE_NAME, ImageDimensions() );
  DALI_TEST_CHECK( nPatchVisual );
  DALI_TEST_CHECK( IsDebugVisual( nPatchVisual ) );

  EnvironmentVariable::SetTestingEnvironmentVariable(false);
  END_TEST;
}
