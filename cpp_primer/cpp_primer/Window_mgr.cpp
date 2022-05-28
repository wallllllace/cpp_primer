//
//  Window_mgr.cpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/5/28.
//

#include "Window_mgr.hpp"


void Window_mgr::clear(ScreenIndex index) {
    Screen& s = screens[index];
    s.contents = string(s.height * s.width, ' ');
}
