//
//  Screen.hpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/5/28.
//

#ifndef Screen_hpp
#define Screen_hpp

#include <stdio.h>
#include <string>
//#include "Window_mgr.hpp"

using namespace std;
class Window_mgr;

class Screen {
public:
    friend class Window_mgr;
    typedef string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c){}
    Screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' '){}
    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
    Screen& move(pos r, pos c);
    void some_member() const; // 可变数据成员，即使在const函数中也能改变值
    Screen& set(char);
    Screen& set(pos, pos, char);
    
    const Screen& display(ostream& os) const ;
    Screen& display(ostream& os);
    
private:
    pos cursor = 0; // 光标位置
    pos height = 0, width = 0; // 屏幕宽和高
    string contents;
    mutable size_t access_ctr;
    void do_display(ostream& os) const;
};

#endif /* Screen_hpp */
