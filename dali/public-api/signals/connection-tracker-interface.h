#ifndef __DALI_CONNECTION_TRACKER_INTERFACE_H__
#define __DALI_CONNECTION_TRACKER_INTERFACE_H__

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

// INTERNAL INCLUDES
#include <dali/public-api/common/dali-common.h>
#include <dali/public-api/signals/signal-slot-observers.h>

namespace Dali
{

/**
 * @brief Interface used to track connections between signals and slots.
 *
 * Performs automatic connection and disconnection when either the slot or signal dies.
 *
 * @code
 * class MyApp : public ConnectionTracker
 * {
 *   Button.ClickedSignal().Connect( this, &MyApp::OnPress );
 *
 *   void OnPress()
 *   {
 *     std::cout << "hello world" << std::endl;
 *   }
 * }
 * @endcode
 *
 * When MyApp is destroyed, it automatically disconnects from Button.ClickSignal.
 * It provides a signal observer interface, to observer when signals are destroyed
 * e.g. if Button object is destroyed while it is still connected.
 */
class DALI_IMPORT_API ConnectionTrackerInterface : public SignalObserver
{
public:

  /**
   * @brief Constructor.
   */
  ConnectionTrackerInterface();

  /**
   * @brief Virtual destructor.
   */
  virtual ~ConnectionTrackerInterface();

  /**
   * @brief Called when a signal is connected.
   *
   * @param[in] slotObserver The slot observer i.e. a signal.
   * @param[in] callback The call back.
   */
  virtual void SignalConnected( SlotObserver* slotObserver, CallbackBase* callback ) = 0;

private:

  ConnectionTrackerInterface( const ConnectionTrackerInterface& );            ///< undefined copy constructor
  ConnectionTrackerInterface& operator=( const ConnectionTrackerInterface& ); ///< undefined assignment operator
};

} // namespace Dali

#endif // __DALI_CONNECTION_TRACKER_INTERFACE_H__
