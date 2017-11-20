/*
 * Copyright (c) 2017 Samsung Electronics Co., Ltd.
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

#include <iostream>
#include <stdlib.h>

// Need to override adaptor classes for toolkit test harness, so include
// test harness headers before dali headers.
#include <dali-toolkit-test-suite-utils.h>

#include <dali.h>
#include <dali-toolkit/dali-toolkit.h>
#include <dali-toolkit/public-api/align-enumerations.h>
#include <dali-toolkit/devel-api/controls/control-devel.h>
#include <dali-toolkit/devel-api/visual-factory/visual-factory.h>
#include <dali-toolkit/devel-api/visuals/image-visual-actions-devel.h>


#include <toolkit-event-thread-callback.h>

#include "dummy-control.h"

using namespace Dali;
using namespace Dali::Toolkit;

void utc_dali_toolkit_control_startup(void)
{
  test_return_value = TET_UNDEF;
}

void utc_dali_toolkit_control_cleanup(void)
{
  test_return_value = TET_PASS;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

namespace
{

bool gObjectCreatedCallBackCalled;

void TestCallback(BaseHandle handle)
{
  gObjectCreatedCallBackCalled = true;
}

void TestVoidCallback()
{
}

static bool gKeyInputFocusCallBackCalled;

static void TestKeyInputFocusCallback( Control control )
{
  tet_infoline(" TestKeyInputFocusCallback");

  gKeyInputFocusCallBackCalled = true;
}

const char* TEST_LARGE_IMAGE_FILE_NAME =  TEST_RESOURCE_DIR "/tbcol.png";
const char* TEST_IMAGE_FILE_NAME =  TEST_RESOURCE_DIR "/gallery-small-1.jpg";

} // namespace

///////////////////////////////////////////////////////////////////////////////////////////////////


int UtcDaliControlConstructor(void)
{
  ToolkitTestApplication application;  // Exceptions require ToolkitTestApplication

  DummyControl dummy;

  DALI_TEST_CHECK( !Control::DownCast(dummy) );

  dummy = DummyControl::New();

  DALI_TEST_CHECK( Control::DownCast(dummy) );
  END_TEST;
}

int UtcDaliControlNew(void)
{
  ToolkitTestApplication application;  // Exceptions require ToolkitTestApplication

  Control control;

  DALI_TEST_CHECK( !Control::DownCast(control) );

  control = Control::New();

  DALI_TEST_CHECK( Control::DownCast(control) );
  END_TEST;
}


int UtcDaliControlRegister(void)
{
  ToolkitTestApplication application;

  // Ensure the object is registered after creation
  ObjectRegistry registry = Stage::GetCurrent().GetObjectRegistry();
  DALI_TEST_CHECK( registry );

  gObjectCreatedCallBackCalled = false;
  registry.ObjectCreatedSignal().Connect( &TestCallback );
  {
    Alignment alignment = Alignment::New();
  }
  DALI_TEST_CHECK( gObjectCreatedCallBackCalled );
  END_TEST;
}

int UtcDaliControlCopyAndAssignment(void)
{
  ToolkitTestApplication application;

  DummyControl control = DummyControl::New();
  Control emptyControl;

  Control controlCopy( control );
  DALI_TEST_CHECK( control == controlCopy );

  Control emptyControlCopy( emptyControl );
  DALI_TEST_CHECK( emptyControl == emptyControlCopy );

  Control controlEquals;
  controlEquals = control;
  DALI_TEST_CHECK( control == controlEquals );

  Control emptyControlEquals;
  emptyControlEquals = emptyControl;
  DALI_TEST_CHECK( emptyControl == emptyControlEquals );

  // Self assignment
  control = control;
  DALI_TEST_CHECK( control == controlCopy );
  END_TEST;
}

int UtcDaliControlDownCast(void)
{
  ToolkitTestApplication application;

  DummyControl control;

  DALI_TEST_CHECK( !Control::DownCast( control ) );

  control = DummyControl::New();

  DALI_TEST_CHECK( Control::DownCast( control ) );

  Actor actor;

  DALI_TEST_CHECK( !Control::DownCast( actor ) );

  actor = Actor::New();

  DALI_TEST_CHECK( !Control::DownCast( actor ) );
  END_TEST;
}

int UtcDaliControlDownCastTemplate(void)
{
  ToolkitTestApplication application;

  DummyControl control;

  DALI_TEST_CHECK( !DummyControl::DownCast( control ));

  control = DummyControl::New();

  DALI_TEST_CHECK( DummyControl::DownCast( control ) );

  Actor actor;

  DALI_TEST_CHECK( !DummyControl::DownCast( actor ) );

  actor = Actor::New();

  DALI_TEST_CHECK( !DummyControl::DownCast( actor ) );
  END_TEST;
}

int UtcDaliControlNavigationProperties(void)
{
  ToolkitTestApplication application;

  Control control = Control::New();
  Stage::GetCurrent().Add( control );

  DALI_TEST_EQUALS( -1, control.GetProperty( DevelControl::Property::LEFT_FOCUSABLE_ACTOR_ID ).Get< int >(), TEST_LOCATION );
  DALI_TEST_EQUALS( -1, control.GetProperty( DevelControl::Property::RIGHT_FOCUSABLE_ACTOR_ID ).Get< int >(), TEST_LOCATION );
  DALI_TEST_EQUALS( -1, control.GetProperty( DevelControl::Property::UP_FOCUSABLE_ACTOR_ID ).Get< int >(), TEST_LOCATION );
  DALI_TEST_EQUALS( -1, control.GetProperty( DevelControl::Property::DOWN_FOCUSABLE_ACTOR_ID ).Get< int >(), TEST_LOCATION );

  control.SetProperty( DevelControl::Property::LEFT_FOCUSABLE_ACTOR_ID, 1 );
  DALI_TEST_EQUALS( 1, control.GetProperty( DevelControl::Property::LEFT_FOCUSABLE_ACTOR_ID ).Get< int >(), TEST_LOCATION );
  control.SetProperty( DevelControl::Property::RIGHT_FOCUSABLE_ACTOR_ID, 2 );
  DALI_TEST_EQUALS( 2, control.GetProperty( DevelControl::Property::RIGHT_FOCUSABLE_ACTOR_ID ).Get< int >(), TEST_LOCATION );
  control.SetProperty( DevelControl::Property::UP_FOCUSABLE_ACTOR_ID, 3 );
  DALI_TEST_EQUALS( 3, control.GetProperty( DevelControl::Property::UP_FOCUSABLE_ACTOR_ID ).Get< int >(), TEST_LOCATION );
  control.SetProperty( DevelControl::Property::DOWN_FOCUSABLE_ACTOR_ID, 4 );
  DALI_TEST_EQUALS( 4, control.GetProperty( DevelControl::Property::DOWN_FOCUSABLE_ACTOR_ID ).Get< int >(), TEST_LOCATION );

  control.SetProperty( DevelControl::Property::LEFT_FOCUSABLE_ACTOR_ID, 15 );
  DALI_TEST_EQUALS( 15, control.GetProperty( DevelControl::Property::LEFT_FOCUSABLE_ACTOR_ID ).Get< int >(), TEST_LOCATION );
  control.SetProperty( DevelControl::Property::RIGHT_FOCUSABLE_ACTOR_ID, 16 );
  DALI_TEST_EQUALS( 16, control.GetProperty( DevelControl::Property::RIGHT_FOCUSABLE_ACTOR_ID ).Get< int >(), TEST_LOCATION );
  control.SetProperty( DevelControl::Property::UP_FOCUSABLE_ACTOR_ID, 17 );
  DALI_TEST_EQUALS( 17, control.GetProperty( DevelControl::Property::UP_FOCUSABLE_ACTOR_ID ).Get< int >(), TEST_LOCATION );
  control.SetProperty( DevelControl::Property::DOWN_FOCUSABLE_ACTOR_ID, 18 );
  DALI_TEST_EQUALS( 18, control.GetProperty( DevelControl::Property::DOWN_FOCUSABLE_ACTOR_ID ).Get< int >(), TEST_LOCATION );

  END_TEST;
}

int UtcDaliControlKeyInputFocus(void)
{
  ToolkitTestApplication application;
  Stage stage = Stage::GetCurrent();

  DummyControl control;

  PushButton pushButton1 = PushButton::New();
  stage.Add( pushButton1 );

  pushButton1.SetKeyInputFocus();
  DALI_TEST_CHECK( pushButton1.HasKeyInputFocus() );

  pushButton1.ClearKeyInputFocus();
  DALI_TEST_CHECK( !pushButton1.HasKeyInputFocus() );
  END_TEST;
}

int UtcDaliControlGetImplementationN(void)
{
  ToolkitTestApplication application;
  DummyControl control;

  // Get Empty
  {
    try
    {
      Toolkit::Internal::Control& controlImpl = Toolkit::Internal::GetImplementation( control );
      (void)controlImpl; // Avoid unused warning
      tet_result(TET_FAIL);
    }
    catch (DaliException &exception)
    {
      tet_result(TET_PASS);
    }
  }
  END_TEST;
}

int UtcDaliControlGetImplementationConstN(void)
{
  ToolkitTestApplication application;
  DummyControl control;

  // Get Const Empty
  {
    try
    {
      const DummyControl constControl(control);
      const Toolkit::Internal::Control& controlImpl = Toolkit::Internal::GetImplementation( constControl );
      (void)controlImpl; // Avoid unused warning
      tet_result(TET_FAIL);
    }
    catch (DaliException &exception)
    {
      tet_result(TET_PASS);
    }
  }
  END_TEST;
}

int UtcDaliControlGetImplementationP(void)
{
  ToolkitTestApplication application;
  DummyControl control = DummyControl::New();

  // Get
  {
    try
    {
      Toolkit::Internal::Control& controlImpl = Toolkit::Internal::GetImplementation( control );
      (void)controlImpl; // Avoid unused warning
      tet_result(TET_PASS);
    }
    catch (DaliException &exception)
    {
      tet_result(TET_FAIL);
    }
  }
  END_TEST;
}

int UtcDaliControlGetImplementationConstP(void)
{
  ToolkitTestApplication application;
  DummyControl control = DummyControl::New();
  // Get Const
  {
    try
    {
      const DummyControl constControl(control);
      const Toolkit::Internal::Control& controlImpl = Toolkit::Internal::GetImplementation( constControl );
      (void)controlImpl; // Avoid unused warning
      tet_result(TET_PASS);
    }
    catch (DaliException &exception)
    {
      tet_result(TET_FAIL);
    }
  }
  END_TEST;
}

int UtcDaliControlSignalConnectDisconnect(void)
{
  ToolkitTestApplication application;

  {
    DummyControl dummy = DummyControlImpl::New();

    Actor actor = Actor::New();
    DALI_TEST_EQUALS( actor.OnStageSignal().GetConnectionCount(), 0u, TEST_LOCATION );
    Toolkit::Internal::Control& control = Toolkit::Internal::GetImplementation( dummy );
    DummyControlImpl* dummyImpl = dynamic_cast<DummyControlImpl*>(&control);

    if( dummyImpl == NULL )
    {
      tet_result( TET_FAIL );
      END_TEST;
    }

    actor.OnStageSignal().Connect( dummyImpl, &DummyControlImpl::CustomSlot1 );
    DALI_TEST_EQUALS( actor.OnStageSignal().GetConnectionCount(), 1u, TEST_LOCATION );
    DALI_TEST_EQUALS( dummyImpl->mCustomSlot1Called, false, TEST_LOCATION );

    Stage::GetCurrent().Add( actor );
    DALI_TEST_EQUALS( dummyImpl->mCustomSlot1Called, true, TEST_LOCATION );

    dummyImpl->mCustomSlot1Called = false;
    actor.OnStageSignal().Disconnect( dummyImpl, &DummyControlImpl::CustomSlot1 );
    DALI_TEST_EQUALS( actor.OnStageSignal().GetConnectionCount(), 0u, TEST_LOCATION );
    Stage::GetCurrent().Remove( actor );
    Stage::GetCurrent().Add( actor );
    DALI_TEST_EQUALS( dummyImpl->mCustomSlot1Called, false, TEST_LOCATION );
  }
  END_TEST;
}

int UtcDaliControlSignalAutomaticDisconnect(void)
{
  ToolkitTestApplication application;

  Actor actor = Actor::New();

  {
    DummyControl dummy = DummyControlImpl::New();
    Toolkit::Internal::Control& control = Toolkit::Internal::GetImplementation( dummy );
    DummyControlImpl* dummyImpl = dynamic_cast<DummyControlImpl*>(&control);

    if( dummyImpl == NULL )
    {
      tet_result( TET_FAIL );
      END_TEST;
    }

    actor.OnStageSignal().Connect( dummyImpl, &DummyControlImpl::CustomSlot1 );
    DALI_TEST_EQUALS( actor.OnStageSignal().GetConnectionCount(), 1u, TEST_LOCATION );
    DALI_TEST_EQUALS( dummyImpl->mCustomSlot1Called, false, TEST_LOCATION );

    Stage::GetCurrent().Add( actor );
    DALI_TEST_EQUALS( dummyImpl->mCustomSlot1Called, true, TEST_LOCATION );
    Stage::GetCurrent().Remove( actor );
  }
  // dummyControl automatically disconnects

  DALI_TEST_EQUALS( actor.OnStageSignal().GetConnectionCount(), 0u, TEST_LOCATION );

  const Vector3 ignoredSize( 20, 20, 0 );
  actor.SetSize( ignoredSize );
  END_TEST;
}

int UtcDaliControlTestParameters(void)
{
  ToolkitTestApplication application;
  DummyControl test = DummyControl::New();

  test.SetSize( 0.7f, 0.7f, 0.7f );

  Stage::GetCurrent().Add( test );

  application.SendNotification();
  application.Render();

  float width = 640.0f;
  float height = test.GetHeightForWidth( width );
  DALI_TEST_EQUALS( 640.0f, height, TEST_LOCATION );
  DALI_TEST_EQUALS( 640.0f, test.GetWidthForHeight( height ), TEST_LOCATION );

  test.KeyEventSignal();

  // Provide coverage for pointer destructor
  Control* testControlPtr = new Control;
  DALI_TEST_CHECK( testControlPtr );
  delete testControlPtr;
  END_TEST;
}

int UtcDaliControlBackgroundColor(void)
{
  ToolkitTestApplication application;
  Control control = Control::New();

  DALI_TEST_EQUALS( control.GetBackgroundColor(), Color::TRANSPARENT, TEST_LOCATION );

  control.SetBackgroundColor( Color::RED );

  Property::Value propValue = control.GetProperty( Control::Property::BACKGROUND );
  Property::Map* resultMap = propValue.GetMap();
  DALI_TEST_CHECK( resultMap->Find( Toolkit::Visual::Property::TYPE ) );
  DALI_TEST_CHECK( resultMap->Find( Toolkit::Visual::Property::TYPE )->Get<int>() == Visual::COLOR );
  DALI_TEST_CHECK( resultMap->Find( ColorVisual::Property::MIX_COLOR ) );
  DALI_TEST_CHECK( resultMap->Find( ColorVisual::Property::MIX_COLOR )->Get<Vector4>() == Color::RED );

  DALI_TEST_EQUALS( control.GetBackgroundColor(), Color::RED, TEST_LOCATION );

  control.SetBackgroundColor( Color::YELLOW );

  propValue = control.GetProperty( Control::Property::BACKGROUND );
  resultMap = propValue.GetMap();
  DALI_TEST_CHECK( resultMap->Find( ColorVisual::Property::MIX_COLOR ) );
  DALI_TEST_CHECK( resultMap->Find( ColorVisual::Property::MIX_COLOR )->Get<Vector4>() == Color::YELLOW );

  DALI_TEST_EQUALS( control.GetBackgroundColor(), Color::YELLOW, TEST_LOCATION );

  END_TEST;
}

int UtcDaliControlBackgroundImage(void)
{
  ToolkitTestApplication application;
  Control control = Control::New();

  DALI_TEST_EQUALS( control.GetBackgroundColor(), Color::TRANSPARENT, TEST_LOCATION );

  Image image = ResourceImage::New("TestImage");
  control.SetBackgroundImage( image );

  Property::Value propValue = control.GetProperty( Control::Property::BACKGROUND );
  Property::Map* resultMap = propValue.GetMap();
  DALI_TEST_CHECK( resultMap->Find( Toolkit::Visual::Property::TYPE ) );
  DALI_TEST_CHECK( resultMap->Find( Toolkit::Visual::Property::TYPE )->Get<int>() == Visual::IMAGE );
  DALI_TEST_CHECK( resultMap->Find( ImageVisual::Property::URL ) );
  DALI_TEST_CHECK( resultMap->Find( ImageVisual::Property::URL )->Get<std::string>() == "TestImage" );

  image = ResourceImage::New("TestImage2");
  control.SetBackgroundImage( image );

  propValue = control.GetProperty( Control::Property::BACKGROUND );
  resultMap = propValue.GetMap();
  DALI_TEST_CHECK( resultMap->Find( ImageVisual::Property::URL ) );
  DALI_TEST_CHECK( resultMap->Find( ImageVisual::Property::URL )->Get<std::string>() == "TestImage2" );

  END_TEST;
}

int UtcDaliControlBackgroundProperties(void)
{
  ToolkitTestApplication application;
  Control control = Control::New();

  DALI_TEST_EQUALS( control.GetBackgroundColor(), Color::TRANSPARENT, TEST_LOCATION );
  DALI_TEST_CHECK( control.GetProperty( Control::Property::BACKGROUND ).Get< Property::Map >().Empty() );

  Property::Map imageMap;
  imageMap[ Toolkit::Visual::Property::TYPE ] = Visual::IMAGE;
  imageMap[ ImageVisual::Property::URL ] = "TestImage";
  control.SetProperty( Control::Property::BACKGROUND, imageMap );
  Property::Value propValue = control.GetProperty( Control::Property::BACKGROUND );
  Property::Map* resultMap = propValue.GetMap();
  DALI_TEST_CHECK( resultMap->Find( Toolkit::Visual::Property::TYPE ) );
  DALI_TEST_EQUALS( resultMap->Find( Toolkit::Visual::Property::TYPE )->Get<int>(),(int)Visual::IMAGE, TEST_LOCATION );
  DALI_TEST_CHECK( resultMap->Find( ImageVisual::Property::URL ) );
  DALI_TEST_EQUALS( resultMap->Find( ImageVisual::Property::URL )->Get<std::string>(), "TestImage", TEST_LOCATION );

  Property::Map rendererMap;
  rendererMap[Visual::Property::TYPE] = Visual::COLOR;
  rendererMap[ColorVisual::Property::MIX_COLOR] = Color::CYAN;
  control.SetProperty( Control::Property::BACKGROUND, rendererMap );
  propValue = control.GetProperty( Control::Property::BACKGROUND );
  resultMap = propValue.GetMap();
  DALI_TEST_CHECK( resultMap->Find( Toolkit::Visual::Property::TYPE ) );
  DALI_TEST_EQUALS( resultMap->Find( Toolkit::Visual::Property::TYPE )->Get<int>(), (int)Visual::COLOR, TEST_LOCATION );
  DALI_TEST_CHECK( resultMap->Find( ColorVisual::Property::MIX_COLOR ) );
  DALI_TEST_EQUALS( resultMap->Find( ColorVisual::Property::MIX_COLOR )->Get<Vector4>(), Color::CYAN, TEST_LOCATION );

  Property::Map emptyMap;
  control.SetProperty( Control::Property::BACKGROUND, emptyMap );
  DALI_TEST_CHECK( control.GetProperty( Control::Property::BACKGROUND ).Get< Property::Map >().Empty() );

  // set as URL
  control.SetProperty( Control::Property::BACKGROUND, "Foobar.png" );
  propValue = control.GetProperty( Control::Property::BACKGROUND );
  resultMap = propValue.GetMap();
  DALI_TEST_EQUALS( resultMap->Find( Toolkit::Visual::Property::TYPE )->Get<int>(), (int)Visual::IMAGE, TEST_LOCATION );
  DALI_TEST_EQUALS( resultMap->Find( ImageVisual::Property::URL )->Get<std::string>(), "Foobar.png", TEST_LOCATION );

  // set as Color
  control.SetProperty( Control::Property::BACKGROUND, Color::RED );
  propValue = control.GetProperty( Control::Property::BACKGROUND );
  resultMap = propValue.GetMap();
  DALI_TEST_EQUALS( resultMap->Find( Toolkit::Visual::Property::TYPE )->Get<int>(), (int)Visual::COLOR, TEST_LOCATION );
  DALI_TEST_EQUALS( resultMap->Find( ColorVisual::Property::MIX_COLOR )->Get<Vector4>(), Color::RED, TEST_LOCATION );

  // Deprecated Properties
  control.SetProperty( Control::Property::BACKGROUND_COLOR, Color::YELLOW );
  DALI_TEST_EQUALS( control.GetProperty( Control::Property::BACKGROUND_COLOR ).Get< Vector4 >(), Color::YELLOW, TEST_LOCATION );
  DALI_TEST_EQUALS( control.GetProperty( Control::Property::BACKGROUND_COLOR ).Get< Vector4 >(), control.GetBackgroundColor(), TEST_LOCATION );

  control.ClearBackground();

  Property::Map deprecatedImageMap;
  deprecatedImageMap[ "filename" ] = "TestImage";
  control.SetProperty( Control::Property::BACKGROUND_IMAGE, deprecatedImageMap );
  propValue = control.GetProperty( Control::Property::BACKGROUND_IMAGE );
  resultMap = propValue.GetMap();
  DALI_TEST_EQUALS( resultMap->Find( ImageVisual::Property::URL )->Get< std::string >(), "TestImage" , TEST_LOCATION );

  control.SetProperty( Control::Property::BACKGROUND_IMAGE, emptyMap );
  DALI_TEST_CHECK( control.GetProperty( Control::Property::BACKGROUND_IMAGE ).Get< Property::Map >().Empty() );

  END_TEST;
}

int UtcDaliControlKeyProperties(void)
{
  ToolkitTestApplication application;

  Control control = Control::New();
  Stage::GetCurrent().Add( control );

  DALI_TEST_EQUALS( control.HasKeyInputFocus(), control.GetProperty( Control::Property::KEY_INPUT_FOCUS ).Get< bool >(), TEST_LOCATION );

  control.SetKeyInputFocus();
  DALI_TEST_EQUALS( true, control.GetProperty( Control::Property::KEY_INPUT_FOCUS ).Get< bool >(), TEST_LOCATION );

  control.ClearKeyInputFocus();
  DALI_TEST_EQUALS( false, control.GetProperty( Control::Property::KEY_INPUT_FOCUS ).Get< bool >(), TEST_LOCATION );

  control.SetProperty( Control::Property::KEY_INPUT_FOCUS, true );
  DALI_TEST_EQUALS( true, control.HasKeyInputFocus(), TEST_LOCATION );

  END_TEST;
}

int UtcDaliControlGestureSignals(void)
{
  ToolkitTestApplication application;
  ConnectionTracker connectionTracker;
  Control control = Control::New();

  // Each gesture detector gets created when connecting to the gesture signals
  DALI_TEST_CHECK( !control.GetTapGestureDetector() );
  control.ConnectSignal( &connectionTracker, "tapped", &TestVoidCallback );
  DALI_TEST_CHECK( control.GetTapGestureDetector() );

  DALI_TEST_CHECK( !control.GetPanGestureDetector() );
  control.ConnectSignal( &connectionTracker, "panned", &TestVoidCallback );
  DALI_TEST_CHECK( control.GetPanGestureDetector() );

  DALI_TEST_CHECK( !control.GetPinchGestureDetector() );
  control.ConnectSignal( &connectionTracker, "pinched", &TestVoidCallback );
  DALI_TEST_CHECK( control.GetPinchGestureDetector() );

  DALI_TEST_CHECK( !control.GetLongPressGestureDetector() );
  control.ConnectSignal( &connectionTracker, "longPressed",  &TestVoidCallback );
  DALI_TEST_CHECK( control.GetLongPressGestureDetector() );

  END_TEST;
}

int UtcDaliControlImplKeyInputFocusGainedSignal(void)
{
  ToolkitTestApplication application;

  Control control = Control::New();
  Stage::GetCurrent().Add( control );

  gKeyInputFocusCallBackCalled = false;
  control.KeyInputFocusGainedSignal().Connect(&TestKeyInputFocusCallback);

  application.SendNotification();
  application.Render();

  control.SetKeyInputFocus();

  DALI_TEST_CHECK( control.HasKeyInputFocus() );

  DALI_TEST_CHECK( gKeyInputFocusCallBackCalled );

  END_TEST;
}

int UtcDaliControlImplKeyInputFocusLostSignal(void)
{
  ToolkitTestApplication application;

  Control control = Control::New();
  Stage::GetCurrent().Add( control );

  gKeyInputFocusCallBackCalled = false;
  control.KeyInputFocusLostSignal().Connect(&TestKeyInputFocusCallback);

  application.SendNotification();
  application.Render();

  control.SetKeyInputFocus();

  DALI_TEST_CHECK( control.HasKeyInputFocus() );

  control.ClearKeyInputFocus();

  DALI_TEST_CHECK( gKeyInputFocusCallBackCalled );

  END_TEST;
}

int UtcDaliControlImplGetControlExtensionP(void)
{
  ToolkitTestApplication application;
  Control control = Control::New();

  Toolkit::Internal::Control& controlImpl = Toolkit::Internal::GetImplementation( control );

  DALI_TEST_CHECK( NULL == controlImpl.GetControlExtension() );

  END_TEST;
}

int UtcDaliControlAutoClipping(void)
{
  ToolkitTestApplication application;
  Control control = Control::New();

  tet_infoline( "Test to see if a renderer gets added when we are clipping children" );

  DALI_TEST_EQUALS( 0, control.GetRendererCount(), TEST_LOCATION );

  control.SetProperty( Actor::Property::CLIPPING_MODE, ClippingMode::CLIP_CHILDREN );

  Stage::GetCurrent().Add( control );

  application.SendNotification();
  application.Render();

  DALI_TEST_EQUALS( 1, control.GetRendererCount(), TEST_LOCATION );

  END_TEST;
}

int UtcDaliControlAutoClippingN(void)
{
  ToolkitTestApplication application;
  Control control = Control::New();
  control.SetProperty( Control::Property::BACKGROUND, Property::Map().Add( Toolkit::Visual::Property::TYPE, Visual::COLOR )
                                                                     .Add( ColorVisual::Property::MIX_COLOR, Color::RED ) );

  tet_infoline( "Test to ensure that a renderer does NOT get added when we are clipping children and already have renderers/visuals" );

  DALI_TEST_EQUALS( 0, control.GetRendererCount(), TEST_LOCATION );

  control.SetProperty( Actor::Property::CLIPPING_MODE, ClippingMode::CLIP_CHILDREN );

  Stage::GetCurrent().Add( control );

  application.SendNotification();
  application.Render();

  DALI_TEST_EQUALS( 1, control.GetRendererCount(), TEST_LOCATION ); // Only 1, not 2

  // Ensure the background color is still RED rather than what's set by the automatic clipping
  Property::Value value = control.GetProperty( Control::Property::BACKGROUND );
  Property::Map* map = value.GetMap();
  DALI_TEST_CHECK( map );
  Property::Value* colorValue = map->Find(ColorVisual::Property::MIX_COLOR );
  DALI_TEST_CHECK( colorValue );
  DALI_TEST_EQUALS( colorValue->Get< Vector4 >(), Color::RED, TEST_LOCATION );

  END_TEST;
}

int UtcDaliControlAutoClippingWhenAlreadyOnStage(void)
{
  ToolkitTestApplication application;
  Control control = Control::New();

  tet_infoline( "Test to see if a renderer gets added when we are clipping children and when already on stage" );

  DALI_TEST_EQUALS( 0, control.GetRendererCount(), TEST_LOCATION );

  Stage::GetCurrent().Add( control );

  application.SendNotification();
  application.Render();

  DALI_TEST_EQUALS( 0, control.GetRendererCount(), TEST_LOCATION );

  control.SetProperty( Actor::Property::CLIPPING_MODE, ClippingMode::CLIP_CHILDREN );

  application.SendNotification();
  application.Render();

  DALI_TEST_EQUALS( 1, control.GetRendererCount(), TEST_LOCATION );

  END_TEST;
}

int UtcDaliControlAutoClippingWhenAlreadyOnStageN(void)
{
  ToolkitTestApplication application;
  Control control = Control::New();
  control.SetProperty( Control::Property::BACKGROUND, Property::Map().Add( Toolkit::Visual::Property::TYPE, Visual::COLOR )
                                                                     .Add( ColorVisual::Property::MIX_COLOR, Color::RED ) );

  tet_infoline( "Test to ensure that a renderer does NOT get added when we are clipping children and already have renderers/visuals and when already on stage" );

  DALI_TEST_EQUALS( 0, control.GetRendererCount(), TEST_LOCATION );

  Stage::GetCurrent().Add( control );

  application.SendNotification();
  application.Render();

  DALI_TEST_EQUALS( 1, control.GetRendererCount(), TEST_LOCATION );

  control.SetProperty( Actor::Property::CLIPPING_MODE, ClippingMode::CLIP_CHILDREN );

  application.SendNotification();
  application.Render();

  DALI_TEST_EQUALS( 1, control.GetRendererCount(), TEST_LOCATION ); // Still should be 1

  // Ensure the background color is still RED rather than what's set by the automatic clipping
  Property::Value value = control.GetProperty( Control::Property::BACKGROUND );
  Property::Map* map = value.GetMap();
  DALI_TEST_CHECK( map );
  Property::Value* colorValue = map->Find(ColorVisual::Property::MIX_COLOR );
  DALI_TEST_CHECK( colorValue );
  DALI_TEST_EQUALS( colorValue->Get< Vector4 >(), Color::RED, TEST_LOCATION );

  END_TEST;
}

int UtcDaliControlSetTransformSize(void)
{
  ToolkitTestApplication application;
  Control control = Control::New();

  Property::Map transformMap;
  transformMap.Add( Visual::Transform::Property::OFFSET, Vector2( 10, 10 ) )
              .Add( Visual::Transform::Property::ANCHOR_POINT, Align::BOTTOM_END )
              .Add( Visual::Transform::Property::ORIGIN, Align::BOTTOM_END )
              .Add( Visual::Transform::Property::SIZE, Vector2( 10, 20 ) );

  control.SetProperty( Control::Property::BACKGROUND, Property::Map().Add( Toolkit::Visual::Property::TYPE, Visual::COLOR )
                                                                     .Add( Visual::Property::TRANSFORM, transformMap ) );

  tet_infoline( "Test to ensure that the control background transform does not get overwritten when adding to the stage" );

  Stage::GetCurrent().Add( control );

  application.SendNotification();
  application.Render();

  // Ensure the transform property still matches what we set
  Property::Value value = control.GetProperty( Control::Property::BACKGROUND );
  Property::Map* map = value.GetMap();
  DALI_TEST_CHECK( map );
  Property::Value* transformValue = map->Find( Visual::Property::TRANSFORM );
  DALI_TEST_CHECK( transformValue );

  Property::Map* retMap = transformValue->GetMap();
  DALI_TEST_CHECK( retMap );
  DALI_TEST_EQUALS( retMap->Find( Visual::Transform::Property::OFFSET )->Get< Vector2 >(), Vector2( 10, 10 ), TEST_LOCATION );
  DALI_TEST_EQUALS( retMap->Find( Visual::Transform::Property::ANCHOR_POINT )->Get< int >(), (int)Align::BOTTOM_END, TEST_LOCATION );
  DALI_TEST_EQUALS( retMap->Find( Visual::Transform::Property::ORIGIN )->Get< int >(), (int)Align::BOTTOM_END, TEST_LOCATION );
  DALI_TEST_EQUALS( retMap->Find( Visual::Transform::Property::SIZE )->Get< Vector2 >(), Vector2( 10, 20 ), TEST_LOCATION );

  END_TEST;
}


int UtcDaliControlResourcesReady(void)
{
  ToolkitTestApplication application;
  tet_infoline( "Register 2 visuals and check ResourceReady when a visual is disabled" );

  VisualFactory factory = VisualFactory::Get();
  DALI_TEST_CHECK( factory );

  Property::Map propertyMapLarge;
  propertyMapLarge.Insert( Toolkit::Visual::Property::TYPE,  Visual::IMAGE );
  propertyMapLarge.Insert( ImageVisual::Property::URL,  TEST_LARGE_IMAGE_FILE_NAME );

  Property::Map propertyMapSmall;
  propertyMapSmall.Insert( Toolkit::Visual::Property::TYPE,  Visual::IMAGE );
  propertyMapSmall.Insert( ImageVisual::Property::URL,  TEST_IMAGE_FILE_NAME );

  Visual::Base smallVisual = factory.CreateVisual( propertyMapSmall );
  smallVisual.SetName("smallVisual");
  DALI_TEST_CHECK( smallVisual );

  DummyControl actor = DummyControl::New();
  DummyControlImpl& dummyImpl = static_cast<DummyControlImpl&>(actor.GetImplementation());
  dummyImpl.RegisterVisual( DummyControl::Property::TEST_VISUAL, smallVisual );

  actor.SetSize( 200.f, 200.f );

  Toolkit::Visual::ResourceStatus resourceStatus = DevelControl::GetVisualResourceStatus(dummyImpl, DummyControl::Property::TEST_VISUAL);
  DALI_TEST_EQUALS( actor.GetRendererCount(), 0u, TEST_LOCATION );
  DALI_TEST_EQUALS( actor.IsResourceReady(), false, TEST_LOCATION );
  DALI_TEST_EQUALS( static_cast<int>(resourceStatus), static_cast<int>(Toolkit::Visual::ResourceStatus::PREPARING), TEST_LOCATION );

  Stage::GetCurrent().Add( actor );
  application.SendNotification();
  application.Render();

  DALI_TEST_EQUALS( Test::WaitForEventThreadTrigger( 1 ), true, TEST_LOCATION );

  application.SendNotification();
  application.Render();

  resourceStatus = DevelControl::GetVisualResourceStatus(dummyImpl, DummyControl::Property::TEST_VISUAL);
  DALI_TEST_EQUALS( actor.GetRendererCount(), 1u, TEST_LOCATION );
  DALI_TEST_EQUALS( actor.IsResourceReady(), true, TEST_LOCATION );
  DALI_TEST_EQUALS( static_cast<int>(resourceStatus), static_cast<int>(Toolkit::Visual::ResourceStatus::READY), TEST_LOCATION );

  Visual::Base largeVisual = factory.CreateVisual( propertyMapLarge );
  largeVisual.SetName("largeVisual");
  DALI_TEST_CHECK( largeVisual );

  tet_infoline( "Register Visual but set disabled, IsResourceReady should be true" );

  dummyImpl.RegisterVisual( DummyControl::Property::TEST_VISUAL2, largeVisual, false );

  resourceStatus = DevelControl::GetVisualResourceStatus(dummyImpl, DummyControl::Property::TEST_VISUAL2);
  DALI_TEST_EQUALS( static_cast<int>(resourceStatus), static_cast<int>(Toolkit::Visual::ResourceStatus::PREPARING), TEST_LOCATION );

  application.SendNotification();

  resourceStatus = DevelControl::GetVisualResourceStatus(dummyImpl, DummyControl::Property::TEST_VISUAL2);
  DALI_TEST_EQUALS( actor.GetRendererCount(), 1u, TEST_LOCATION );
  DALI_TEST_EQUALS( actor.IsResourceReady(), true, TEST_LOCATION );
  DALI_TEST_EQUALS( static_cast<int>(resourceStatus), static_cast<int>(Toolkit::Visual::ResourceStatus::PREPARING), TEST_LOCATION );

  dummyImpl.EnableVisual( DummyControl::Property::TEST_VISUAL2, true );

  DALI_TEST_EQUALS( Test::WaitForEventThreadTrigger( 1 ), true, TEST_LOCATION );

  application.SendNotification();

  resourceStatus = DevelControl::GetVisualResourceStatus(dummyImpl, DummyControl::Property::TEST_VISUAL2);
  DALI_TEST_EQUALS( static_cast<int>(resourceStatus), static_cast<int>(Toolkit::Visual::ResourceStatus::READY), TEST_LOCATION );

  END_TEST;
}

int UtcDaliControlMarginProperty(void)
{
  ToolkitTestApplication application;

  Control control = Control::New();
  control.SetBackgroundColor( Color::BLUE );

  control.SetProperty( Control::Property::MARGIN, Extents( 20, 10, 0, 0 ) );

  Stage::GetCurrent().Add( control );

  application.SendNotification();
  application.Render();

  DALI_TEST_EQUALS( control.GetProperty<Extents>( Control::Property::MARGIN ), Extents( 20, 10, 0, 0 ), TEST_LOCATION );

  // Parent control has one ImageView as a Child.
  ImageView image = ImageView::New();
  image.SetBackgroundColor( Color::RED );
  image.SetResizePolicy( ResizePolicy::FILL_TO_PARENT, Dimension::ALL_DIMENSIONS );
  image.SetProperty( Control::Property::PADDING, Extents( 10, 10, 10, 10 ) );
  control.Add( image );

  application.SendNotification();
  application.Render();

  DALI_TEST_EQUALS( image.GetProperty<Extents>( Control::Property::PADDING ), Extents( 10, 10, 10, 10 ), TEST_LOCATION );

  END_TEST;
}

int UtcDaliControlPaddingProperty(void)
{
  ToolkitTestApplication application;

  Control control = Control::New();
  control.SetBackgroundColor( Color::BLUE );

  control.SetProperty( Control::Property::PADDING, Extents( 15, 10, 5, 10 ) );

  Stage::GetCurrent().Add( control );

  application.SendNotification();
  application.Render();

  DALI_TEST_EQUALS( control.GetProperty<Extents>( Control::Property::PADDING ), Extents( 15, 10, 5, 10 ), TEST_LOCATION );

  Control child = Control::New();
  control.Add(child);

  application.SendNotification();
  application.Render();

  DALI_TEST_EQUALS( child.GetProperty<Vector3>( Dali::Actor::Property::POSITION ), Vector3( 15, 5, 0 ), TEST_LOCATION );

  control.SetProperty( Dali::Actor::Property::LAYOUT_DIRECTION,  Dali::LayoutDirection::RIGHT_TO_LEFT);
  application.SendNotification();
  application.Render();
  DALI_TEST_EQUALS( child.GetProperty<Vector3>( Dali::Actor::Property::POSITION ), Vector3( 10, 5, 0 ), TEST_LOCATION );

  control.SetProperty( Dali::Actor::Property::LAYOUT_DIRECTION,  Dali::LayoutDirection::LEFT_TO_RIGHT);
  application.SendNotification();
  application.Render();

  DALI_TEST_EQUALS( child.GetProperty<Vector3>( Dali::Actor::Property::POSITION ), Vector3( 15, 5, 0 ), TEST_LOCATION );

  END_TEST;
}

int UtcDaliControlDoAction(void)
{
  ToolkitTestApplication application;
  tet_infoline( "DoAction on a visual registered with a control" );

  // Set up trace debug
  TestGlAbstraction& gl = application.GetGlAbstraction();
  TraceCallStack& textureTrace = gl.GetTextureTrace();
  textureTrace.Enable( true );

  //Created AnimatedImageVisual
  VisualFactory factory = VisualFactory::Get();
  Visual::Base imageVisual = factory.CreateVisual( TEST_IMAGE_FILE_NAME, ImageDimensions() );

  DummyControl dummyControl = DummyControl::New(true);
  Impl::DummyControl& dummyImpl = static_cast<Impl::DummyControl&>(dummyControl.GetImplementation());

  dummyImpl.RegisterVisual( DummyControl::Property::TEST_VISUAL, imageVisual );
  dummyControl.SetSize(200.f, 200.f);
  Stage::GetCurrent().Add( dummyControl );

  DALI_TEST_EQUALS( Test::WaitForEventThreadTrigger( 1 ), true, TEST_LOCATION );

  application.SendNotification();
  application.Render();
  DALI_TEST_EQUALS( textureTrace.CountMethod("DeleteTextures"), 0, TEST_LOCATION );
  DALI_TEST_EQUALS( textureTrace.FindMethod("GenTextures"), true, TEST_LOCATION );
  textureTrace.Reset();

  Property::Map attributes;
  DevelControl::DoAction( dummyControl,  DummyControl::Property::TEST_VISUAL, DevelImageVisual::Action::RELOAD, attributes );

  tet_infoline( "Perform RELOAD action. should reload Image and generate a texture" );
  DALI_TEST_EQUALS( Test::WaitForEventThreadTrigger( 1 ), true, TEST_LOCATION );

  application.SendNotification();
  application.Render();
  DALI_TEST_EQUALS( textureTrace.CountMethod("DeleteTextures"), 1, TEST_LOCATION );
  DALI_TEST_EQUALS( textureTrace.FindMethod("GenTextures"), true, TEST_LOCATION );
  END_TEST;
}

int UtcDaliControlDoActionWhenNotStage(void)
{
  ToolkitTestApplication application;
  tet_infoline( "DoAction on a visual registered with a control but not staged" );

  // Set up trace debug
  TestGlAbstraction& gl = application.GetGlAbstraction();
  TraceCallStack& textureTrace = gl.GetTextureTrace();
  textureTrace.Enable( true );

  //Created AnimatedImageVisual
  VisualFactory factory = VisualFactory::Get();
  Visual::Base imageVisual = factory.CreateVisual( TEST_IMAGE_FILE_NAME, ImageDimensions() );

  DummyControl dummyControl = DummyControl::New(true);
  Impl::DummyControl& dummyImpl = static_cast<Impl::DummyControl&>(dummyControl.GetImplementation());

  dummyImpl.RegisterVisual( DummyControl::Property::TEST_VISUAL, imageVisual );
  dummyControl.SetSize(200.f, 200.f);

  application.SendNotification();
  application.Render();
  DALI_TEST_EQUALS( textureTrace.CountMethod("DeleteTextures"), 0, TEST_LOCATION );
  DALI_TEST_EQUALS( textureTrace.FindMethod("GenTextures"), false, TEST_LOCATION );
  textureTrace.Reset();

  Property::Map attributes;
  DevelControl::DoAction( dummyControl,  DummyControl::Property::TEST_VISUAL, DevelImageVisual::Action::RELOAD, attributes );

  tet_infoline( "Perform RELOAD action. should reload Image and generate a texture" );
  DALI_TEST_EQUALS( Test::WaitForEventThreadTrigger( 1 ), true, TEST_LOCATION );

  application.SendNotification();
  application.Render();
  DALI_TEST_EQUALS( textureTrace.FindMethod("GenTextures"), true, TEST_LOCATION );
  textureTrace.Reset();

  tet_infoline( "Adding control to stage will in turn add the visual to the stage" );

  Stage::GetCurrent().Add( dummyControl );
  application.SendNotification();
  application.Render();
  tet_infoline( "No change in textures could occurs as already loaded and cached texture will be used" );

  DALI_TEST_EQUALS( textureTrace.CountMethod("DeleteTextures"), 0, TEST_LOCATION );
  DALI_TEST_EQUALS( textureTrace.FindMethod("GenTextures"), false, TEST_LOCATION );
  textureTrace.Reset();

  END_TEST;
}
