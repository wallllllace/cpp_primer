//
//  Message.cpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/6/4.
//

#include "Message.hpp"
#include "Folder.hpp"

void swap(Message& lhs, Message& rhs) {
    using std::swap;
    for (auto& f : lhs.folders) {
        f->removeMsg(&lhs);
    }
    for (auto& f : rhs.folders) {
        f->removeMsg(&rhs);
    }
    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);
    for (auto& f : lhs.folders) {
        f->addMsg(&lhs);
    }
    for (auto& f : rhs.folders) {
        f->addMsg(&rhs);
    }
}

void Message::add_to_folder(const Message& m) {
    for (auto& f : m.folders) {
        f->addMsg(this);
    }
}

void Message::remove_from_folders(){
    for (auto& f : folders) {
        f->removeMsg(this);
    }
}

Message::Message(const Message& m): contents(m.contents), folders(m.folders) {
    add_to_folder(m);
}

Message& Message::operator=(const Message& rhs) {
    remove_from_folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_folder(rhs);
    return *this;
}

Message::~Message() {
    remove_from_folders();
}

void Message::save(Folder& f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder& f) {
    folders.erase(&f);
    f.removeMsg(this);
}
