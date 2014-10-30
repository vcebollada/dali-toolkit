// Prevent normal accessibility manager declaration from loading
#define __DALI_ACCESSIBILITY_MANAGER_H__

#ifndef __DALI_TOOLKIT_ACCESSIBILITY_MANAGER_H__
#define __DALI_TOOLKIT_ACCESSIBILITY_MANAGER_H__

/*
 * Copyright (c) 2014 Samsung Electronics Co., Ltd.
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

// EXTERNAL INCLUDES
#include <string>
#include <boost/function.hpp>
#include <dali/public-api/object/base-handle.h>
#include <dali/public-api/signals/dali-signal-v2.h>
#include <dali/public-api/events/touch-point.h>

namespace Dali
{
namespace Internal
{
namespace Adaptor
{
class AccessibilityManager;
}
}
class AccessibilityActionHandler;
class AccessibilityGestureHandler;
class TouchPoint;

/**
 * This creates a stubbed AccessibilityManager so that internal Toolkit Adaptor calls work.
 */
class AccessibilityManager : public BaseHandle
{
public: // Typedefs
  typedef SignalV2< bool ( AccessibilityManager& ) > AccessibilityActionSignalV2;

public: // Construction & Destruction
  AccessibilityManager();
  ~AccessibilityManager();

public: // Getters
  static AccessibilityManager Get();
  Vector2 GetReadPosition() const;
  bool IsEnabled() const;
  void SetActionHandler(AccessibilityActionHandler& handler);
  void SetGestureHandler(AccessibilityGestureHandler& handler);
  bool HandleActionNextEvent();
  bool HandleActionPreviousEvent();
  bool HandleActionActivateEvent();
  bool HandleActionReadEvent(unsigned int x, unsigned int y, bool allowReadAgain);
  bool HandleActionReadNextEvent();
  bool HandleActionReadPreviousEvent();
  bool HandleActionUpEvent();
  bool HandleActionDownEvent();
  bool HandleActionClearFocusEvent();
  bool HandleActionScrollEvent(TouchPoint& point, unsigned long timeStamp);
  bool HandleActionBackEvent();
  void HandleActionEnableEvent();
  void HandleActionDisableEvent();

public:  // Signals
  AccessibilityActionSignalV2& StatusChangedSignal();
  AccessibilityActionSignalV2& ActionNextSignal();
  AccessibilityActionSignalV2& ActionPreviousSignal();
  AccessibilityActionSignalV2& ActionActivateSignal();
  AccessibilityActionSignalV2& ActionReadSignal();
  AccessibilityActionSignalV2& ActionOverSignal();
  AccessibilityActionSignalV2& ActionReadNextSignal();
  AccessibilityActionSignalV2& ActionReadPreviousSignal();
  AccessibilityActionSignalV2& ActionUpSignal();
  AccessibilityActionSignalV2& ActionDownSignal();
  AccessibilityActionSignalV2& ActionClearFocusSignal();
  AccessibilityActionSignalV2& ActionBackSignal();

  AccessibilityManager( Internal::Adaptor::AccessibilityManager* manager );
};

} // namespace Dali

#endif // __DALI_TOOLKIT_ACCESSIBILITY_MANAGER_H__
