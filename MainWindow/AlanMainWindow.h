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
#ifndef IKARUS_PROJECT_ALANMAINWINDOW_H
#define IKARUS_PROJECT_ALANMAINWINDOW_H


#include <QMainWindow>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include "../res/errors/AlanMainWindowErrors.h"
#include "../res/version.h"
#include "../res/generic_text/AlanMainWindowText.h"
#include "../res/img/generic_paths.h"
#include "../Factory/AbstractFactory.h"
#include "../Supplier/LogSupplier/LogSupplier.h"
#include "../InformationObject/Option/ChildOptions/ClientStatusOption.h"
#include "../InformationObject/Option/ChildOptions/WindowHandleOption.h"

/*****
 * AlanMainWindow
 * This QMainWindow is the main GUI window of AlanStreamer
 * @Note . For the future maintainer . if you want to add something . there is the steps you need to make
 * 1) if it is something like "GUI small change" , then just work on current methods as..
 *                  onGenerateMenu();
 *                  onGenerateToolBar();
 *                  onGenerateLeftLayout();
 *                  onGenerateVideoArea();
 *                  onGenerateRightLayout();
 *      in case of any error , just throw an exception , everything else is take care of the layered-error-controlling
 *      design of AlanMainWindow
 * 2) if you want to add new stuff (another panel maybe?) you must follow this layered-error-controlling design
 *    the method genericInitializer is a generic function , called by constructor . this function calls every other
 *    sub-initilizer for every distinct part of this window..
 *    for example , the video area is created by a call to onGenerateVideoArea() from initializeCentralWidget() who is called
 *    by genericInitializer()
 *    ==============================================Why ?========================================================
 *
 *    AlanMainWindow(Just like any other visual element in this programm) is created using a layered-error-checking technuque
 *    in this technique , we have the genericInitializer , who is responsible for the whole initialization , the
 *    per-window-part initializer , who is responsible to take the part and fit in inside MainWindow . and the part-constructor
 *    who creates the actual part
 *    ============================================Give me an example!!===========================================
 *    Okay then ! whow the menu is initialized ?
 *    The call chain is ...
 *                      genericInitializer()->initializeMenu()->onGenerateMenu()
 *    The genericInitializer calls all sub-part initializer's the initializeMenu() is responsible for any error happened on
 *    onGenerateMenu() . this method returns a vector with menu's! . the initializeMenu() takes the ready Menus and
 *    fit in MainWindow ^^
 *
 *    =====================================The reason?===========================================================
 *    if you want to change completely some part , just extend this class and override any of sub-part method.
 *    the only thing you need to do , is to return the new part. it is not essential to read and re-understand the
 *    whole code . ^^
 *
 */
class AlanMainWindow : public QMainWindow{
    Q_OBJECT

public:
    AlanMainWindow(AbstractFactory*factory);
private :
    //Misc Members
    bool isStreaming;
    bool isReTransmitting;
    AbstractFactory*parentFactory;
    LogSupplier*supplier;
    OptionSupplier*rtspClientOptionSupplier;
    InformationObjectSupplier*dataExporterSupplier;
    InformationObjectSupplier*logExporterSupplier;


private:


    //Initializers

    bool genericInitializer();              ///@return true if all initialization steps was successful
    bool initializeMenu();                  ///@return true if the menu initialization process was successful
    bool initializeToolBar();               ///@return true if ToolBar initialization process was successful
    bool initializeCentralWidget();
    //Misc
    QAction* initializeQAction(QAction *act,QString filename, const char*onClickSlot);
    void   changeStatusOfRTSPClientSubsystem(ClientStatus status);
    void   setWindowHandlerOfRTSPClientSubsystem(const WId status);


protected slots:
    void operationNotSupportedSlot();   //Shows a Warning message that the pressed QAction is not supported
    void genericActionSlot();
    void closeSlot();                   //triggers on QAction "Exit" //TODO connect with closeEvent() also
protected:
    std::vector<QMenu*>*                onGenerateMenu(QMenuBar*bar) throw(std::exception);
    std::vector<QToolBar*>*             onGenerateToolBar() throw(std::exception);
    QWidget*                            onGenerateCentralWidget()throw(std::exception);
    QWidget*                            onGenerateLeftLayout()throw(std::exception);
    QWidget*                            onGenerateVideoArea()throw(std::exception);
    QWidget*                            onGenerateRightLayout()throw(std::exception);
    LogSupplier                         *getSupplier() const;
    OptionSupplier                      *getRtspClientOptionSupplier() const;
    void                                _utill_locationNotifier(InformationObjectSupplier *subsystemSuppplier, QString location);



};


#endif //IKARUS_PROJECT_ALANMAINWINDOW_H
