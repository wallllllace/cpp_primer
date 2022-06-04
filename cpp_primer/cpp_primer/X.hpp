//
//  X.hpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/6/3.
//

#ifndef X_hpp
#define X_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class X {
    
public:
    X(){
        cout << "x()" << endl;
    }
    
    X(const X&) {
        cout << "X(const X&)" << endl;
    }
    
    ~X() {
        cout << "~X()" << endl;
    }
    
    X& operator=(const X& rhs) {
        cout << "operator=(const X& rhs)" << endl;
        return *this;
    }
};

#endif /* X_hpp */
