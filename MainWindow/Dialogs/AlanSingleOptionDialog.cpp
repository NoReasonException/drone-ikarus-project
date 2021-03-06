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
#include <QVBoxLayout>
#include <QLabel>
#include <QDialog>
#include <QWindow>
#include <iostream>
#include "AlanSingleOptionDialog.h"

AlanSingleOptionDialog::AlanSingleOptionDialog(AlanSingleOptionDialogState* Currstate,const QString &title,const QString&icon):
        titleArea(title),
        iconArea(icon),
        state(Currstate){

}
/***
 * @note . if you create a final class derived from AlanSingleOptionDialog , you need to call in the final generic_initializer the restoreState()!
 * @return
 */
bool AlanSingleOptionDialog::generic_initializer() {
    return layoutInitializer();
}
QWidget *AlanSingleOptionDialog::onGenerateTitleArea() throw(std::exception) {
    QWidget*widget=new QWidget;
    QHBoxLayout*lay=new QHBoxLayout();
    widget->setLayout(lay);
    lay->addWidget(new QLabel(titleArea),0,Qt::AlignCenter);
    return widget;
}
QWidget *AlanSingleOptionDialog::onGenerateIconArea() throw (std::exception){
    QLabel*lbl=new QLabel;
    lbl->setPixmap(QPixmap(iconArea));
    return lbl;
}
bool AlanSingleOptionDialog::layoutInitializer()try {
    setLayout(mainLay=onGenerateLayout());
    mainLay->addWidget(onGenerateLeftmostArea());
    mainLay->addWidget(onGenerateRightMostArea());
    return true;
}catch(std::exception&e){return false;}

QLayout *AlanSingleOptionDialog::onGenerateLayout() throw(std::exception) {
    return new QHBoxLayout();
}

QWidget *AlanSingleOptionDialog::onGenerateLeftmostArea() throw(std::exception) {
    return onGenerateIconArea();
}

QWidget *AlanSingleOptionDialog::onGenerateRightMostArea() throw(std::exception) {
    QWidget*dia=new QWidget;
    QLayout*lay;
    dia->setLayout(lay=new QVBoxLayout);
    lay->addWidget(onGenerateTitleArea());
    lay->addWidget(onGenerateConfigArea());
    lay->addWidget(onGenerateButtonsArea());
    return dia;
}

AlanSingleOptionDialogState * AlanSingleOptionDialog::onRestoreState() throw(std::exception) {
    return state;
}
AlanSingleOptionDialogState * AlanSingleOptionDialog::onSaveState() throw(std::exception) {
    return state;
}

AlanSingleOptionDialogState *AlanSingleOptionDialog::getState() const {

    return state;
}

AlanSingleOptionDialog *AlanSingleOptionDialog::prepare() {
    return generic_initializer()?this: nullptr;
}
