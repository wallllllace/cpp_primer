//
//  HasPtr1.cpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/6/3.
//

#include "HasPtr1.hpp"


HasPtr1&
HasPtr1::operator=(const HasPtr1& hp){
    if (*use == 1) {
        delete ps;
        delete use;
    }
    ++(*hp.use);
    ps = hp.ps;
    i = hp.i;
    use = hp.use;
    return *this;
}

