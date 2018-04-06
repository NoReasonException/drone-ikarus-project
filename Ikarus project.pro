######################################################################
# Automatically generated by qmake (3.1) Sat Mar 31 18:09:50 2018
######################################################################
QT += widgets multimediawidgets
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
SOURCES += ./main.cpp \
           ./MainWindow/Supplier/InformationObjectSupplier.cpp \
           ./MainWindow/Supplier/LogSupplier/LogSupplier.cpp \
           ./MainWindow/AlanMainWindow.cpp \
           ./MainWindow/Panels/AlanPanel.cpp \
           ./MainWindow/Panels/StreamPanel/LogPanel/LogWidget/LogWidget.cpp \
           ./MainWindow/Panels/StreamPanel/LogPanel/LogPanel.cpp \
           ./MainWindow/Panels/StreamPanel/StreamPanel.cpp \
           ./MainWindow/Consumer/LogConsumer/LogConsumer.cpp \
           ./MainWindow/Consumer/InformationObjectConsumer.cpp \
           ./MainWindow/InformationObject/InformationObject.cpp \
           ./MainWindow/InformationObject/Data/Data.cpp \
           ./MainWindow/InformationObject/Log/Log.cpp \
           MainWindow/Dialogs/AlanSingleOptionDialog.cpp


HEADERS +=  ./MainWindow/Interfaces/LogSupplierFactory.h \
            ./MainWindow/Interfaces/InformationSupplierFactory.h \
            ./MainWindow/Supplier/LogSupplier/LogSupplier.h \
            ./MainWindow/Supplier/InformationObjectSupplier.h \
            ./MainWindow/Panels/AlanPanel.h \
            ./MainWindow/Panels/StreamPanel/LogPanel/LogWidget/LogWidget.h \
            ./MainWindow/Panels/StreamPanel/LogPanel/LogPanel.h \
            ./MainWindow/Panels/StreamPanel/StreamPanel.h \
            ./MainWindow/AlanMainWindow.h \
            ./MainWindow/Consumer/InformationObjectConsumer.h \
            ./MainWindow/Consumer/LogConsumer/LogConsumer.h \
            ./MainWindow/InformationObject/InformationObject.h \
            ./MainWindow/InformationObject/Data/Data.h \
            ./MainWindow/InformationObject/Log/Log.h \
            ./misc/version.h \
            ./misc/img/generic_paths.h \
            ./misc/generic_text/generic_dialogs.h \
            ./misc/generic_text/AlanMainWindowDialogs.h \
            ./misc/errors/AlanMainWindowErrors.h \
            ./misc/errors/AlanPanelErrors.h \
            MainWindow/Dialogs/AlanSingleOptionDialog.h






