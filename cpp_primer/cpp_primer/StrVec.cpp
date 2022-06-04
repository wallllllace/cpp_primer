//
//  StrVec.cpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/6/4.
//

#include "StrVec.hpp"


void StrVec::chk_n_alloc() {
    if (cap == first_free) {
        reallocate(); // 
    }
}

pair<string*, string*>
StrVec::alloc_n_copy(const string* b, const string* e) {
    auto p = alloc.allocate(e-b);
    auto q = uninitialized_copy(b, e, p); //
    return {p, q};
}

void StrVec::free() {
    if (elements) {
        auto p = first_free;
        while (p != elements) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, capacity()); //
    }
}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    auto p = alloc.allocate(newcapacity);
    auto dest = p;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++)); //
    }
    free();
    elements = p;
    first_free = dest;
    cap = elements + newcapacity;
}

StrVec::StrVec(const StrVec& v) {
    auto p = alloc_n_copy(v.begin(), v.end());
    elements = p.first;
    first_free = cap = p.second;
}

StrVec::~StrVec() {
    free(); //
}

StrVec&
StrVec::operator=(const StrVec& rhs) {
    auto p = alloc_n_copy(rhs.begin(), rhs.end());
    free(); //
    elements = p.first;
    first_free = cap = p.second;
    return *this;
}


void StrVec::push_back(const string& s) {
    chk_n_alloc();
    alloc.construct(first_free++, s); //
}
