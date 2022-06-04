//
//  Folder.hpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/6/4.
//

#ifndef Folder_hpp
#define Folder_hpp

#include <stdio.h>
#include <set>

using namespace std;

class Message;
class Folder {
    
public:
    Folder()=default;
    ~Folder();
    
    void addMsg(Message *);
    void removeMsg(Message *);
    
private:
    set<Message*> messages;
};

#endif /* Folder_hpp */

