//
// Created by noreasonexception on 4/1/18.
//

#ifndef IKARUS_PROJECT_ALANMAINWINDOW_H
#define IKARUS_PROJECT_ALANMAINWINDOW_H


#include <QMainWindow>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include "../misc/errors/AlanMainWindowErrors.h"
#include "../misc/version.h"
#include "../misc/generic_text/AlanMainWindowDialogs.h"
#include "../misc/img/generic_paths.h"
#include "../Factory/AbstractFactory.h"
#include "../Supplier/LogSupplier/LogSupplier.h"

/***
 * AlanMainWindow
 * This window is the main window of Alan Streamer , inherits from QMainWindow
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


    //Initializers

    bool genericInitializer();              ///@return true if all initialization steps was successful
    bool initializeMenu();                  ///@return true if the menu initialization process was successful
    bool initializeToolBar();               ///@return true if ToolBar initialization process was successful
    bool initializeCentralWidget();
    //Misc
    QAction* initializeQAction(QAction *act,QString filename, const char*onClickSlot);


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

    LogSupplier *getSupplier() const;


};


#endif //IKARUS_PROJECT_ALANMAINWINDOW_H
