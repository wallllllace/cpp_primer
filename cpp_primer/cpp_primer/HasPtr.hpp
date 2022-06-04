//
//  HasPtr.hpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/6/3.
//

#ifndef HasPtr_hpp
#define HasPtr_hpp

#include <stdio.h>
#include <string>
#include <memory>

using namespace std;


class HasPtr {
    
public:
    friend void Swap(HasPtr&, HasPtr&);
    
    HasPtr(const string& s): ps(new string(s)) { }
    HasPtr(const HasPtr& hp): ps(new string(*hp.ps)), i(hp.i) { }
//    HasPtr& operator=(const HasPtr& rhs);
    HasPtr& operator=(const HasPtr rhs);
    ~HasPtr() {
        delete ps;
    }
private:
    string *ps;
    int i;
};

void Swap(HasPtr& lhs, HasPtr& rhs) ;

#endif /* HasPtr_hpp */
