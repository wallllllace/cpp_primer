//
//  ConstRef.hpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/5/28.
//

#ifndef ConstRef_hpp
#define ConstRef_hpp

#include <stdio.h>

class ConstRef {
    
public:
//    ConstRef(int ii): i(ii), ci(ii),ri(i) {}; // 要么在构造函数初始化列表初始化，要么有初始值，在构造函数体初始化实际是在给初始值赋值。
    ConstRef(int ii);
private:
    int i = 0;
    const int ci = 0;
    int &ri = i;
};

#endif /* ConstRef_hpp */
