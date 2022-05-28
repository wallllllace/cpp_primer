//
//  Screen.cpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/5/28.
//

#include "Screen.hpp"

inline char Screen::get(pos ht, pos wd) const {
    pos row = wd * width;
    return contents[row + ht];
}

Screen& Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

void Screen::some_member() const {
    access_ctr++;
}

Screen& Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

Screen& Screen::set(pos ht, pos wd, char c) {
    contents[wd * width + ht] = c;
    return *this;
}

const Screen& Screen::display(ostream& os) const {
    do_display(os);
    return *this;
}

Screen& Screen::display(ostream& os) {
    do_display(os);
    return  *this;
}

void Screen::do_display(ostream& os) const {
    os << contents;
}
