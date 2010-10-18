/*=============================================================================

  Library: CTK

  Copyright (c) 2010 German Cancer Research Center,
    Division of Medical and Biological Informatics

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=============================================================================*/


#ifndef CTKPLUGINTRACKERPRIVATE_H
#define CTKPLUGINTRACKERPRIVATE_H

#include "ctkPlugin.h"

#include <QSharedPointer>
#include <QMutex>

class ctkPluginTracker;
class ctkPluginContext;
class ctkTrackedPlugin;
class ctkPluginTrackerCustomizer;

class ctkPluginTrackerPrivate
{
public:
  ctkPluginTrackerPrivate(ctkPluginTracker* pt,
                          ctkPluginContext* context, ctkPlugin::States stateMask,
                          ctkPluginTrackerCustomizer* customizer);

  ~ctkPluginTrackerPrivate();

  /**
   * Accessor method for the current ctkTrackedPlugin object. This method is only
   * intended to be used by the unsynchronized methods which do not modify the
   * trackedPlugin field.
   *
   * @return The current ctkTrackedPlugin object.
   */
  QSharedPointer<ctkTrackedPlugin> tracked() const;

  /* set this to true to compile in debug messages */
  static const bool DEBUG; //	= false;

  /**
   * The Bundle Context used by this <code>ctkPluginTracker</code>.
   */
  ctkPluginContext* const context;

  /**
   * The <code>ctkPluginTrackerCustomizer</code> object for this tracker.
   */
  ctkPluginTrackerCustomizer* customizer;

  /**
   * Tracked plugins: <code>ctkPlugin</code> object -> customized Object and
   * plugin listener slot.
   */
  QSharedPointer<ctkTrackedPlugin> trackedPlugin;

  /**
   * State mask for plugins being tracked. This field contains the ORed values
   * of the plugin states being tracked.
   */
  ctkPlugin::States mask;

  mutable QMutex mutex;

private:

  Q_DECLARE_PUBLIC(ctkPluginTracker)

  ctkPluginTracker * const q_ptr;
};

#endif // CTKPLUGINTRACKERPRIVATE_H
