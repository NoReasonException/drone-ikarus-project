//
// Created by noreasonexception on 4/3/18.
//

#include "LogSupplier.h"

LogSupplier::LogSupplier(const QString _supplierName,InformationObjectConsumer*target) :
        InformationObjectSupplier(_supplierName,target) {}
