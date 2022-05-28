//
//  Window_mgr.hpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/5/28.
//

#ifndef Window_mgr_hpp
#define Window_mgr_hpp

#include <stdio.h>
#include <vector>
#include "Screen.hpp"

using namespace std;

class Window_mgr {
    
public:
    typedef vector<Screen>::size_type ScreenIndex ;
    void clear(ScreenIndex);
    
private:
    vector<Screen> screens{Screen(24, 80, ' ')};
};

#endif /* Window_mgr_hpp */
