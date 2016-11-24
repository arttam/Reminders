//
// Created by art on 15/07/16.
//

#ifndef REMINDER_DATAPROVIDER_H
#define REMINDER_DATAPROVIDER_H
#include <string>
#include <QStringList>

#include "DataEntry.h"

struct IDataProvider
{
    virtual ~IDataProvider() = default;

    virtual bool isValid() = 0;
    virtual QStringList *getKeys() = 0;
    virtual const EntryStruct *getListItem(const QString key) const = 0;
    virtual bool setListItem(const EntryStruct& value) = 0;
    virtual bool removeListItem(const std::string &key) = 0;
    virtual bool saveItems() = 0;
};

#endif //REMINDER_DATAPROVIDER_H
