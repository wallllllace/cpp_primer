//
//  HasPtr1.hpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/6/3.
//

#ifndef HasPtr1_hpp
#define HasPtr1_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class HasPtr1 {
    
public:
    HasPtr1(string& s): ps(new string(s)), use(new int(1)) { } // 是否传递引用只是表示从实参到形参是否拷贝，但是后面用实参初始化成员变量肯定是另外一个地址了。
    HasPtr1(const HasPtr1& hp): ps(hp.ps), i(hp.i), use(hp.use){ (*use)++; }
    ~HasPtr1() {
        (*use)--;
        if (*use == 0) {
            delete ps;
            delete use;
        }
    }
    HasPtr1& operator=(const HasPtr1& hp);
private:
    string *ps;
    int i;
    int *use;
    
};

#endif /* HasPtr1_hpp */
