#ifndef DALI_TOOLKIT_DEVEL_API_VISUALS_VISUAL_PROPERTIES_DEVEL_H
#define DALI_TOOLKIT_DEVEL_API_VISUALS_VISUAL_PROPERTIES_DEVEL_H

/*
 * Copyright (c) 2020 Samsung Electronics Co., Ltd.
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

// INTERNAL INCLUDES
#include <dali-toolkit/public-api/visuals/visual-properties.h>

namespace Dali
{

namespace Toolkit
{

namespace DevelVisual
{

/**
 * @brief All the visual types.
 */
enum Type
{
  BORDER         = Dali::Toolkit::Visual::BORDER,
  COLOR          = Dali::Toolkit::Visual::COLOR,
  GRADIENT       = Dali::Toolkit::Visual::GRADIENT,
  IMAGE          = Dali::Toolkit::Visual::IMAGE,
  MESH           = Dali::Toolkit::Visual::MESH,
  PRIMITIVE      = Dali::Toolkit::Visual::PRIMITIVE,
  WIREFRAME      = Dali::Toolkit::Visual::WIREFRAME,
  TEXT           = Dali::Toolkit::Visual::TEXT,
  N_PATCH        = Dali::Toolkit::Visual::N_PATCH,
  SVG            = Dali::Toolkit::Visual::SVG,
  ANIMATED_IMAGE = Dali::Toolkit::Visual::ANIMATED_IMAGE,

  ANIMATED_GRADIENT     = ANIMATED_IMAGE + 1,  ///< Renders an animated gradient.
  ANIMATED_VECTOR_IMAGE = ANIMATED_IMAGE + 2,  ///< Renders an animated vector image.
  ARC                   = ANIMATED_IMAGE + 3,  ///< Renders an arc.
};

/**
 * @brief Visual Properties
 */
namespace Property
{
enum Type
{
  TYPE                = Dali::Toolkit::Visual::Property::TYPE,
  SHADER              = Dali::Toolkit::Visual::Property::SHADER,
  TRANSFORM           = Dali::Toolkit::Visual::Property::TRANSFORM,
  PREMULTIPLIED_ALPHA = Dali::Toolkit::Visual::Property::PREMULTIPLIED_ALPHA,
  MIX_COLOR           = Dali::Toolkit::Visual::Property::MIX_COLOR,
  OPACITY             = Dali::Toolkit::Visual::Property::OPACITY,

  /**
   * @brief The fitting mode of the visual
   * @details Name "fittingMode", type FittingMode (Property::INTEGER) or Property::STRING.
   * @see DevelVisual::FittingMode
   * @note The default is defined by the type of visual (if it's suitable to be stretched or not).
   */
  VISUAL_FITTING_MODE = OPACITY + 1,

  /**
   * @brief The radius for the rounded corners of the visual
   * @details Name "cornerRadius", type Property::FLOAT.
   * @note Optional.
   */
  CORNER_RADIUS = OPACITY + 2,
};

} // namespace Property


/**
 * @brief The values of this enum determine how the visual should be fit to the view
 */
enum FittingMode
{
  FIT_KEEP_ASPECT_RATIO,  ///< The visual should be scaled to fit, preserving aspect ratio
  FILL,                   ///< The visual should be stretched to fill, not preserving aspect ratio
};

/**
 * @brief Devel Visual Transform for the offset or size.
 */
namespace Transform
{

/**
 * @brief Visual Transform Property.
 */
namespace Property
{

/**
 * @brief Enumeration for the type of Transform Property.
 */
enum Type
{
  SIZE_POLICY = Dali::Toolkit::Visual::Transform::Property::SIZE_POLICY,

  /**
   * @brief Extra size value that will be added to the computed visual size.
   * @details Name "extraSize", type Vector2.
   *
   * @note It is an absolute value.
   *       The property can be used when a user want to set a visual size as a combined value of `relative` and `absolute`.
   *       For example, when a user want to set a visual size to (ControlSize * 2 + 10),
   *       The transform map will be,
   *       transformMap.Add( Transform::Property::SIZE, Vector2( 2.0f, 2.0f ) )
   *                   .Add( Transform::Property::SIZE_POLICY, Vector2( Transform::Policy::Relative, Transform::Policy::Relative ) )
   *                   .Add( Transform::Property::EXTRA_SIZE, Vector2( 10.0f, 10.0f ) );
   */
  EXTRA_SIZE = SIZE_POLICY + 1,
};

} // namespace Property

} // namespace Transform

} // namespace DevelVisual

} // namespace Toolkit

} // namespace Dali

#endif // DALI_TOOLKIT_DEVEL_API_VISUALS_VISUAL_PROPERTIES_DEVEL_H
