//
// Created by art on 15/07/16.
//

#ifndef REMINDER_FILEPROVIDER_H
#define REMINDER_FILEPROVIDER_H
#include <QStringList>
#include <memory>
#include <map>
#include <unordered_map>
#include <typeindex>
#include <iostream>

#include "DataEntry.h"
#include "QtDataProvider.h"
#include "ISTLProvider.h"

class FileProviderImpl;

class DataProvider: public IDataProvider {
    QStringList *keys;

public:

    using Supported = std::unordered_map<std::string, std::type_index>;
    using SIt       = Supported::const_iterator;

    DataProvider(const std::string& type, const std::string& source);
    virtual ~DataProvider();

    bool isValid() override;

    virtual QStringList *getKeys();
    virtual const EntryStruct *getListItem(const QString key) const override ;
    virtual bool setListItem(const EntryStruct& value) override ;
    virtual bool removeListItem(const std::string &key) override ;
    virtual bool saveItems() override;

private:
    static Supported supportedSources;

    std::unique_ptr<ISTLProvider> impl;
};


#endif //REMINDER_FILEPROVIDER_H
