######################################################################
# Automatically generated by qmake (3.1) Sat Mar 31 18:09:50 2018
######################################################################
QT += widgets multimediawidgets core
PKGCONFIG += Qt5GStreamer-1.0 Qt5GLib-2.0
QMAKE_CXXFLAGS+= -std=c++0x $(pkg-config --cflags --libs gstreamer-1.0)

TEMPLATE = app
TARGET = "Ikarus project"
INCLUDEPATH += .
LIBS -= GStreamer

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
SOURCES += ./Supplier/InformationObjectSupplier.cpp \
           ./Supplier/LogSupplier/LogSupplier.cpp \
           ./Supplier/OptionSupplier/OptionSupplier.cpp \
           ./Consumer/LogConsumer/LogConsumer.cpp \
           ./Consumer/InformationObjectConsumer.cpp \
           ./main.cpp \
           ./MainWindow/AlanMainWindow.cpp \
           ./MainWindow/Factory/AbstractGuiFactory.cpp \
           ./MainWindow/Factory/AlanDefaultGuiFactory/AlanDefaultGuiFactory.cpp \
           ./MainWindow/Dialogs/AlanSingleOptionDialog.cpp \
           ./MainWindow/Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/AlanMultipleChoiceDialog.cpp \
           ./MainWindow/Dialogs/AlanTwoButtonDialog/AlanTwoButtonDialog.cpp \
           ./MainWindow/Panels/AlanPanel.cpp \
           ./MainWindow/Panels/StreamPanel/LogPanel/LogWidget/LogWidget.cpp \
           ./MainWindow/Panels/StreamPanel/LogPanel/LogPanel.cpp \
           ./MainWindow/Panels/StreamPanel/StreamPanel.cpp \
           ./MainWindow/State/State.cpp \
           ./InformationObject/InformationObject.cpp \
           ./InformationObject/Data/Data.cpp \
           ./InformationObject/Log/Log.cpp \
           ./InformationObject/Option/Option.cpp \






HEADERS +=  ./Consumer/InformationObjectConsumer.h \
            ./Consumer/LogConsumer/LogConsumer.h \
            ./MainWindow/Factory/AbstractGuiFactory.h \
            ./MainWindow/Factory/AlanDefaultGuiFactory/AlanDefaultGuiFactory.h \
            ./MainWindow/Dialogs/ChildDialogs/AlanAboutDialog.h \
            ./MainWindow/Dialogs/AlanTwoButtonDialog/AlanTwoButtonDialog.h \
            ./MainWindow/Dialogs/AlanTwoButtonDialog/ChildDialogs/SetResolutionDialog.h \
            ./MainWindow/Dialogs/AlanTwoButtonDialog/ChildDialogs/SetLatencyDialog.h \
            ./MainWindow/Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/ChildDialogs/SetServersAddrDialog.h \
            ./MainWindow/Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/ChildDialogs/SetDroneAddrDialog.h \
            ./MainWindow/Dialogs/AlanTwoButtonDialog/AlanMultipleChoiceDialog/AlanMultipleChoiceDialog.h \
            ./MainWindow/Dialogs/AlanSingleOptionDialog.h \
            ./MainWindow/Panels/AlanPanel.h \
            ./MainWindow/Panels/StreamPanel/LogPanel/LogWidget/LogWidget.h \
            ./MainWindow/Panels/StreamPanel/LogPanel/LogPanel.h \
            ./MainWindow/Panels/StreamPanel/StreamPanel.h \
            ./MainWindow/AlanMainWindow.h \
            ./MainWindow/State/WindowStates/AlanTwoButtonsDialogState/AlanMultipleChoiceDialogState/AlanMultipleChoiceDialogState.h \
            ./MainWindow/State/WindowStates/AlanTwoButtonsDialogState/AlanMultipleChoiceDialogState/ChildStates/SetServersAddrDialogState.h \
            ./MainWindow/State/WindowStates/AlanTwoButtonsDialogState/AlanMultipleChoiceDialogState/ChildStates/SetDroneAddrDialogState.h \
            ./MainWindow/State/WindowStates/AlanTwoButtonsDialogState/AlanTwoButtonsDialogState.h \
            ./MainWindow/State/WindowStates/AlanTwoButtonsDialogState/ChildStates/SetResolutionDialogState.h \
            ./MainWindow/State/WindowStates/AlanTwoButtonsDialogState/ChildStates/SetLatencyDialogState.h \
            ./MainWindow/State/WindowStates/AlanSingleOptionDialogState.h \
            ./MainWindow/State/State.h \
            ./InformationObject/InformationObject.h \
            ./InformationObject/Data/Data.h \
            ./InformationObject/Log/Log.h \
            ./InformationObject/Option/ChildOptions/LatencyOption.h \
            ./InformationObject/Option/ChildOptions/ResolutionOption.h \
            ./InformationObject/Option/ChildOptions/ClientStatusOption.h \
            ./InformationObject/Option/Option.h \
            ./Interfaces/LogSupplierFactory.h \
            ./Interfaces/StateRestorable.h \ \
            ./Interfaces/InformationSupplierFactory.h \
            ./misc/states.h \
            ./misc/version.h \
            ./misc/Suppliers/LogSuppliers.h \
            ./misc/img/generic_paths.h \
            ./misc/generic_text/AlanMainWindowMisc.h \
            ./misc/generic_text/generic_dialogs.h \
            ./misc/generic_text/AlanMainWindowDialogs.h \
            ./misc/errors/AlanMainWindowErrors.h \
            ./misc/errors/AlanPanelErrors.h \
            ./Supplier/LogSupplier/LogSupplier.h \
            ./Supplier/OptionSupplier/OptionSupplier.h \
            ./Supplier/InformationObjectSupplier.h













