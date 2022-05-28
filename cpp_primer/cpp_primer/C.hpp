//
//  C.hpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/5/28.
//

#ifndef C_hpp
#define C_hpp

#include <stdio.h>
#include <vector>
#include "NoDefault.hpp"

using namespace std;

class C {
    
public:
    C(int i): nd(NoDefault(i)) {}
    C():C(0){}
private:
    NoDefault nd;
    vector<NoDefault> v;
};
#endif /* C_hpp */
