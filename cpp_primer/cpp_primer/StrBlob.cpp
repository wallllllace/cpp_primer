//
//  StrBlob.cpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/5/30.
//

#include "StrBlob.hpp"
#include "StrBlobPtr.hpp"

StrBlob::StrBlob(): data(make_shared<vector<string>>()) {}

StrBlob::StrBlob(initializer_list<string> il): data( make_shared<vector<string>>(il)) {}

void StrBlob::pop_back() {
    check(0, "pop_back on empty strBlob");
    data->pop_back();
}
// 元素访问
string& StrBlob::front() {
    return static_cast<const StrBlob *>(this)->front();
}

string& StrBlob::back(){
    return  static_cast<const StrBlob *>(this)->back();
}

string& StrBlob::front() const {
    if (empty()) {
        check(0, "front on empty strBlob");
    }
    return data->at(data->size()-1);
}

string& StrBlob::back() const {
    if (empty()) {
        check(0, "back on empty strBlob");
    }
    return data->at(0);
}

void StrBlob::check(size_t i, const string & msg) const {
    if (i < data->size()) {
        return;
    }
    throw out_of_range(msg);
}

ostream& StrBlob::look(ostream& os) const {
    for (auto& i : *data) {
        os << i << " ";
    }
    return os;
}


StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this, 0);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, size());
}


