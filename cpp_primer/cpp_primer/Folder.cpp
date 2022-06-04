//
//  Folder.cpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/6/4.
//

#include "Folder.hpp"
#include "Message.hpp"

void Folder::addMsg(Message* m) {
    messages.insert(m);
}

void Folder::removeMsg(Message* m) {
    messages.erase(m);
}

Folder::~Folder() {
    for (auto& m : messages) {
        m->remove(*this);
    }
}

