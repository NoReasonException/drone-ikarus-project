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
#ifndef IKARUS_PROJECT_ABSTRACTRTSPCLIENTSUBSYSTEM_H
#define IKARUS_PROJECT_ABSTRACTRTSPCLIENTSUBSYSTEM_H


#include <QMutex>
#include "../Consumer/OptionConsumer/OptionConsumer.h"
#include "../Interfaces/OptionSupplierFactory.h"
#include "../Supplier/LogSupplier/LogSupplier.h"
#include "../InformationObject/Option/ChildOptions/LatencyOption.h"
#include "../InformationObject/Option/ChildOptions/LocationOption.h"
#include "../InformationObject/Option/ChildOptions/ResolutionOption.h"
#include "../InformationObject/Option/ChildOptions/ClientStatusOption.h"
#include "../InformationObject/Option/ChildOptions/WindowHandleOption.h"
#include "../Supplier/DataSupplier/DataSupplier.h"
/*****
 * The AbstractRTSPClientSubsystem
 * This subsystems handles all the data , the metadata , the streaming , the video drawing .. everything!
 * This subsystem follow some rules to communicate with outside world (GUI-Space mostly)
 * @Note : for the future maintainer . DONT VIOLATE THE RULES .It is very common the "Quick and dirty code"
 * but all this little extra complexity is for your own good . you need only 10-20 minutes to understand the concept
 * dont ignore the documentation .
 * :)
 *
 * =======================================How it works?=========================================
 * The RTSP Subsystem is a consumer , that means that it implements the OptionConsumer class and has implemented a
 * member .accept() . This member will accept objects of specific type and every communication between the
 * subsystem and the outside world will happen through that .accept() call . The accept call currently accept objects
 * of 5 types , as shown below...
 *                      1) ClientStatusOption , to change the sub-systems state (see below)
 *                      2) LatencyOption      , to change the latency between server-client buffers
 *                      3) LocationOption     , to set the server address and port
 *                      4) ResolutionOption   , to set the width and the height of video ( has some problems //TODO )
 *                      5) WindowHandleOption , to set the X window handle ID for video .
 * The concept of states...
 * The RTSP Subsystem works with the concept of States , just like gstreamer . After initialize the
 * pointer, you need to #START the subsystem . so to initialize itself , after that ,you can #PLAY or #PAUSE
 * and in deletion of pointer , the destruction sequence is started under the #STOP state
 * If you are familiar with gstreamer , then this board will be useful for you..
 *  GST_STATE_NULL       #STOP
 *
 *  GST_STATE_READY      #START
 *
 *  GST_STATE_PAUSED     #PAUSED
 *
 *  GST_STATE_PLAYING    #PLAY
 *
 * Although the default implementation uses gstreamer ,the OOP hierarchy ensures that any library can be used easily!
 *@Note why so much complexity ? I future releases , i hope to write async handlers for this , to ensure the
 * minimum latency possible , so this design is nesessary for this
 */
class AbstractRTSPClientSubsystem : public OptionConsumer,
                                    public OptionSupplierFactory{
public:
    AbstractRTSPClientSubsystem();
    virtual ~AbstractRTSPClientSubsystem()= default;

private:
    LogSupplier*supplier;
    DataSupplier*dataSupplier;
    OptionSupplier*self_supplier;


private:
    QMutex *consumerLocker;

public:
    void accept(InformationObjectSupplier *supplier, InformationObject *info) override;

    OptionSupplier *createSupplier(QString supplierName) override;
    LogSupplier *getLogSupplier() const;
    DataSupplier *getDataSupplier() const;
    OptionSupplier *getSelf_supplier();
protected:

    //@may be null
    virtual bool onLatencySettingChangedHandler(class LatencyOption*)=0;
    virtual bool onResolutionSettingChangedHandler(class ResolutionOption*)=0;
    virtual bool onClientStatusSettingChangedHandler(class ClientStatusOption*)=0;
    virtual bool onWindowHandlerSettingChangedHandler(class WindowHandleOption*)=0;
    virtual bool onLocationSettingChangedHandler(class LocationOption*)=0;




};


#endif //IKARUS_PROJECT_ABSTRACTRTSPCLIENTSUBSYSTEM_H
