//
// Created by art on 20/09/16.
//

#include <list>
#include "DbProviderImpl.h"

DbProviderImpl::DbProviderImpl(const std::string &source) : source_{source}
{

}

bool DbProviderImpl::read() {
    return false;
}

std::list<std::string> &DbProviderImpl::getKeys() {
    if (keys_.empty()) {
        if (items_.empty()) {
            read();
        }
        for(auto item: items_)
            keys_.push_back(item.first);
    }
    return keys_;
}

const EntryStruct *DbProviderImpl::getListItem(const std::string &key) const {
    return nullptr;
}

bool DbProviderImpl::setListItem(const EntryStruct &item) {
    return false;
}

bool DbProviderImpl::removeListItem(const std::string &key) {
    return false;
}

bool DbProviderImpl::save() {
    return false;
}

