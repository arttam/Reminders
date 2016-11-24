//
// Created by art on 15/07/16.
//

#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "FileProviderImpl.h"

bool FileProviderImpl::read()
{
    std::ifstream sample(source_);
    if (!sample)
        return false;

    std::string _line;
    std::string tokens[4]{"", "", "", ""};
    while(std::getline(sample, _line)) {
        int _currToken = 0;
        std::istringstream _iss(_line);
        while(std::getline(_iss, tokens[_currToken], ':')) {
            ++_currToken;
        }
        items_[tokens[0]] = {tokens[0], tokens[1], tokens[2], tokens[3]};
        std::transform(std::begin(tokens), std::end(tokens), std::begin(tokens), [](std::string) { return std::string{""}; });
    }
    sample.close();
    return true;
}

std::list<std::string>& FileProviderImpl::getKeys()
{
    if (keys_.empty()) {
        if (items_.empty()) {
            read();
        }
        for(auto item: items_)
            keys_.push_back(item.first);
    }
    return keys_;
}

const EntryStruct *FileProviderImpl::getListItem(const std::string& key) const
{
    CIt _item = items_.find(key);
    if (_item == items_.end())
        return nullptr;

    return &_item->second;
}

bool FileProviderImpl::setListItem(const EntryStruct &item) {
    WIt _item = items_.find(item.key);
    if (_item == items_.end()) {
        items_.emplace(item.key, item);
        keys_.push_back(item.key);
    }
    else {
        _item->second = item;
    }

    return true;
}

bool FileProviderImpl::removeListItem(const std::string &key)
{
    WIt _delMe = items_.find(key);
    if (_delMe != items_.end()) {
        items_.erase(key);
    }

    return true;
}

bool FileProviderImpl::save() {
    std::ofstream ofs(source_, std::ios_base::trunc);
    if (ofs) {
        std::copy(items_.begin(), items_.end(), std::ostream_iterator<Items::value_type>(ofs));
    }
    return false;
}
