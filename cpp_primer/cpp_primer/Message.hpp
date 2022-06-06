//
//  Message.hpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/6/4.
//

#ifndef Message_hpp
#define Message_hpp

#include <stdio.h>
#include <string>
#include <set>

using namespace std;

class Folder;
class Message {
    friend class Folder;
    friend void swap(Message&, Message&);
public:
    explicit Message(const string& str = ""): contents(str) { }
    Message(const Message&);
    Message(Message&&);
    Message& operator=(const Message&);
    Message& operator=(Message&&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
    
private:
    string contents; // 实际消息文本
    set<Folder *> folders; // 包含本message的folder
    void add_to_folder(const Message&); // 将本message添加到指向参数的folder中
    void remove_from_folders(); // 从folders中的每个folder中删除message
};

void swap(Message&, Message&);

#endif /* Message_hpp */
