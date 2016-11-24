//
// Created by art on 15/07/16.
//

#include "DataProvider.h"
#include "FileProviderImpl.h"
#include "DbProviderImpl.h"

DataProvider::Supported DataProvider::supportedSources = {
    {"file", typeid(FileProviderImpl)},
    {"db", typeid(DbProviderImpl)}
};

DataProvider::DataProvider(const std::string& type, const std::string& source): keys{nullptr}, impl{nullptr}
{
    SIt instanceType = std::find_if(supportedSources.begin(), supportedSources.end(),
        [&type](Supported::value_type& item) {
            return (item.first == type);
        });

    if (instanceType == supportedSources.end())
        return;

    if (instanceType->second == typeid(FileProviderImpl)) {
        impl.reset(new FileProviderImpl(source));
    }
    else if (instanceType->second == typeid(DbProviderImpl))
        impl.reset(new DbProviderImpl(source));
}

bool DataProvider::isValid(){
    if (!impl)
        return false;

    return impl->read();
}

DataProvider::~DataProvider()
{
    if (keys != nullptr)
        delete keys;
}

QStringList *DataProvider::getKeys()
{
    if (keys == nullptr) {
        keys = new QStringList();
        for (auto key : impl->getKeys()) {
            keys->push_back(key.c_str());
        }
    }

    return keys;
}

const EntryStruct *DataProvider::getListItem(const QString key) const
{
    return impl->getListItem(key.toStdString());
}

bool DataProvider::setListItem(const EntryStruct& value)
{
    return impl->setListItem(value);
}

bool DataProvider::removeListItem(const std::string &key)
{
    // TODO: Don't forget to remove key from keys
    return impl->removeListItem(key);
}

bool DataProvider::saveItems() {
    return impl->save();
}
