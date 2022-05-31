//
//  StrBlobPtr.cpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/5/31.
//

#include "StrBlobPtr.hpp"

shared_ptr<vector<string>>
StrBlobPtr::check(size_type i, const string& msg) const {
    shared_ptr<vector<string>> sp = wptr.lock();
    if (!sp) {
        throw runtime_error("unbound StrBlobPtr");
    }
    if (i >= sp->size()) {
        throw out_of_range(msg);
    }
    return sp;
}

string& StrBlobPtr::deref() const {
    auto p = check(curr, "out of range on deref");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
    auto p = check(curr, "out of range on incr");
    ++curr;
    return *this;
}

bool StrBlobPtr::isEnd() const {
    auto sp = wptr.lock();
    if (!sp) {
        throw runtime_error("unbound StrBlobPtr");
    }
    return curr >= sp->size();
}


