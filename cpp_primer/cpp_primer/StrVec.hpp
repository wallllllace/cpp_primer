//
//  StrVec.hpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/6/4.
//

#ifndef StrVec_hpp
#define StrVec_hpp

#include <stdio.h>
#include <memory>
#include <string>

using namespace std;

class StrVec {
    
public:
    StrVec():elements(nullptr), first_free(nullptr), cap(nullptr){ }
    StrVec(const StrVec&);
    ~StrVec();
    StrVec& operator=(const StrVec&);
    void push_back(const string&);
    size_t size() const { return first_free - elements ;}
    size_t capacity() const { return cap - elements;}
    string* begin() const {return elements;}
    string* end() const {return first_free;}
    
private:
    allocator<string> alloc;
    void chk_n_alloc();
    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();
    void reallocate();
    string* elements; // 指向分配内存中的首元素
    string* first_free; // 指向最后一个实际元素之后的位置
    string* cap; // 指向分配的内存末尾之后的位置
};

#endif /* StrVec_hpp */
