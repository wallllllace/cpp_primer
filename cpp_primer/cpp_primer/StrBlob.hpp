//
//  StrBlob.hpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/5/30.
//

#ifndef StrBlob_hpp
#define StrBlob_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

class StrBlobPtr;

class StrBlob {
    
public:
    friend class StrBlobPtr;
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const { return data->size();}
    bool empty() const { return data->empty(); }
    // 添加删除元素
    void push_back(const string& s){ data->push_back(s); }
    void pop_back();
    // 元素访问
    string& front();
    string& back();
    string& front() const;
    string& back() const;
    ostream& look(ostream&) const;
    
    StrBlobPtr begin();
    StrBlobPtr end();
private:
    shared_ptr<vector<string>> data = make_shared<vector<string>>();
    void check(size_t i, const string & msg) const;
};




#endif /* StrBlob_hpp */
