#ifndef __DALI_TOOLKIT_CLIPBOARD_EVENT_NOTIFIER_H__
#define __DALI_TOOLKIT_CLIPBOARD_EVENT_NOTIFIER_H__

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

// PUBLIC INCLUDES
#include <dali/public-api/clipboard-event-notifier.h>

namespace Dali
{

namespace Internal
{
namespace Adaptor
{
class ClipboardEventNotifier;
}
}

/**
 * This creates a stubbed ClipboardEventNotifier so that internal Toolkit Adaptor calls work.
 */
class ToolkitClipboardEventNotifier
{
public: // Constants

public: // Construction & Destruction

  ToolkitClipboardEventNotifier();
  ~ToolkitClipboardEventNotifier();

public: // Getters

  ClipboardEventNotifier GetClipboardEventNotifier();

public: // Signal Emissions

  ClipboardEventNotifier::ClipboardEventSignalV2& SignalContentSelected();

public: // TEST FUNCTIONS

private:

  Internal::Adaptor::ClipboardEventNotifier* mClipboardEventNotifierStub;
  friend class Internal::Adaptor::ClipboardEventNotifier;
  ClipboardEventNotifier mClipboardEventNotifier; // Hold a handle ourselves.
};

} // namespace Dali

#endif // __DALI_TOOLKIT_TOOLKIT_CLIPBOARD_EVENT_NOTIFIER_H__
