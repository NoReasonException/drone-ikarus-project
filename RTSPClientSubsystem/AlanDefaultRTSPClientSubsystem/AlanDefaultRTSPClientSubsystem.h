//
// Created by noreasonexception on 4/14/18.
//

#ifndef IKARUS_PROJECT_ALANDEFAULTRTSPCLIENTSUBSYSTEM_H
#define IKARUS_PROJECT_ALANDEFAULTRTSPCLIENTSUBSYSTEM_H


#include <QSettings>
#include "../AbstractRTSPClientSubsystem.h"
#include "qsettings.h"

class AlanDefaultRTSPClientSubsystem: public AbstractRTSPClientSubsystem {

private :
    QSettings settings;
    bool isNullThenLog(void *ptr,QString message);
    bool isWindowHandleDefined=false;
    bool isClientStatusDefined=false;
    ClientStatus currentStatus;
    int windowHandle;
protected:
    void onLatencySettingChangedHandler(class LatencyOption *) override;

    void onResolutionSettingChangedHandler(class ResolutionOption *) override;

    void onClientStatusSettingChangedHandler(class ClientStatusOption *) override;

    void onWindowHandlerSettingChangedHandler(class WindowHandleOption *) override;

};


#endif //IKARUS_PROJECT_ALANDEFAULTRTSPCLIENTSUBSYSTEM_H