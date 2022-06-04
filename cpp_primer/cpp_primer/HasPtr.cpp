//
//  HasPtr.cpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/6/3.
//

#include "HasPtr.hpp"
#include <iostream>


inline void Swap(HasPtr& lhs, HasPtr& rhs) {
   using std::swap;
   swap(lhs.ps, rhs.ps);
   swap(lhs.i, rhs.i);
}

//HasPtr&
//HasPtr::operator=(const HasPtr& rhs) {
////    delete ps; // 不能直接释放ps，因为如果rhs和this是同一个对象，则rhs.ps也被释放掉了
////    ps = new string(*rhs.ps);
////    i = rhs.i;
////    return *this;
//    cout << "operator=(const HasPtr& rhs)" << endl;
//    auto tmp = new string(*rhs.ps);
//    delete ps;
//    ps = tmp;
//    i = rhs.i;
//    return *this;
//}

HasPtr&
HasPtr::operator=(HasPtr rhs) {
    cout << "operator=(HasPtr rhs) " << endl;
//    swap(*this, rhs);
    ::Swap(*this, rhs);
    return *this;
}


