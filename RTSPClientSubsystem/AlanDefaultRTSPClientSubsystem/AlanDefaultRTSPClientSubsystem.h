/*
 * Copyright (C) 2018 Stefanos Stefanou
 * This file is part of AlanStreamer.

    AlanStreamer is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    AlanStreamer is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.


    You should have received a copy of the GNU General Public License
    along with AlanStreamer.  If not, see <http://www.gnu.org/licenses/>.

 */
#ifndef IKARUS_PROJECT_ALANDEFAULTRTSPCLIENTSUBSYSTEM_H
#define IKARUS_PROJECT_ALANDEFAULTRTSPCLIENTSUBSYSTEM_H


#include <QSettings>
#include <gst/gstelementfactory.h>

#include <gst/video/videooverlay.h>
#include "../AbstractRTSPClientSubsystem.h"
#include "qsettings.h"
#include "MainLoopThread.h"

extern "C" int  trigger_new_frame(void *alanDefaultRTSPClientSubsystem_entity,unsigned long ID,unsigned long TIMESTAMP);

class AlanDefaultRTSPClientSubsystem: public AbstractRTSPClientSubsystem {
    friend int  trigger_new_frame (void *alanDefaultRTSPClientSubsystem_entity,unsigned long ID,unsigned long TIMESTAMP);

public:
    AlanDefaultRTSPClientSubsystem();
    ~AlanDefaultRTSPClientSubsystem() override ;

private :
    QSettings settings;
    bool _utill_isNullThenLog(void *ptr, const QString &onErrorMessage);
    bool isWindowHandleDefined=false;
    bool isClientStatusDefined=false;
    bool isFileSinkLocationDefined=true;
    bool isgstrtspsrcLocationDefined=true;
    bool isqueueLatencyDefined=true;
    bool isGstreamerSubsystemInitialized=false;
    ClientStatus currentStatus;
    int windowHandle;
    //Etc:
    guint   major,
            minor,
            nano,
            pico;
    //Handlers:
    gulong  on_timestamp_export_probe_triggered_probe_id,
            rtspsrc_pad_added_signal_id,
            decodebin_pad_added_signal_id;

    //Factories
    GstElementFactory
            *gstrtspsrc_fact,
            *queue_fact,
            *rtph264depayloader_fact,
            *tee_fact,
                    *save_sink_queue_fact,  //branch to save stream into file
                    *filesink_fact,
                *to_screen_queue_fact,      //branch to show video on screen
                *decodebin_fact,
                *videoconvert_fact,
                *ximagesink_fact;
    ///Elements:
    GstElement
            *pipeline,
            *gstrtspsrc_elem,
            *queue_elem,
            *rtph264depayloader_elem,
            *tee_elem,
                    *save_sink_queue_elem,
                    *filesink_elem,
                *to_screen_queue_elem,
                *decodebin_elem,
                *videoconvert_elem,
                *ximagessink_elem;
    //Functional :
    GMainLoop   *mainLoop;
    class MainLoopThread*mainLoopThread;
    GstBus      *mainBus;

    //Initialization:
    bool initializeGstreamer();
    bool _initializeFactories();
    bool _initializeElements();
    bool _initializeConnections();
    bool _applyProperties();
    bool _initializeBus();
    bool _initializePadAddedListeners();
    bool _initializeProbeListeners();
    //Destruction Sequence:
    bool de_initializeGstreamer();
    bool _de__initializeFactories();
    bool _de__initializeElements();
    bool _de__initializeConnections();
    bool _de__applyProperties();
    bool _de__initializeBus();
    bool _de__initializePadAddedListeners();
    bool _de__initializeProbeListeners();
    //Utills:
    bool _utillLogHandler(bool status,const QString &onSuccessTitle,const QString &onSuccessMsg);
    bool _utill_gst_object_unref_many(int i,...);
    //Etc:
    virtual bool propertyChangedHandler();

protected:

    virtual bool callProperStatusHandler(ClientStatus status);
    //Property Handlers:
    bool onLatencySettingChangedHandler(class LatencyOption *) override;

    bool onResolutionSettingChangedHandler(class ResolutionOption *) override;

    bool onClientStatusSettingChangedHandler(class ClientStatusOption *) override;

    bool onWindowHandlerSettingChangedHandler(class WindowHandleOption *) override;

    bool onLocationSettingChangedHandler(class LocationOption *obj) override;

    //Status handlers
    virtual bool onStartStatusRequest();
    virtual bool onPlayStatusRequest();
    virtual bool onPauseStatusRequest();
    virtual bool onStopStatusRequest();


};


#endif //IKARUS_PROJECT_ALANDEFAULTRTSPCLIENTSUBSYSTEM_H
