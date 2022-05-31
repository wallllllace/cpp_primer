//
//  StrBlobPtr.hpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/5/31.
//

#ifndef StrBlobPtr_hpp
#define StrBlobPtr_hpp

#include <stdio.h>
#include <memory>
#include <vector>
#include <string>
#include "StrBlob.hpp"

using namespace std;

class StrBlobPtr {
    
public:
    typedef vector<string>::size_type size_type;
    StrBlobPtr(): curr(0) {}
    StrBlobPtr(StrBlob& b, size_type i): wptr(b.data), curr(i) {}
    string& deref() const;
    StrBlobPtr& incr(); // 前缀递增
    bool isEnd() const;
private:
    // 若检查成功，check返回一个指向vector的shared_ptr
    shared_ptr<vector<string>>
    check(size_type i, const string& msg) const;
    
    weak_ptr<vector<string>> wptr;
    size_type curr;
};


#endif /* StrBlobPtr_hpp */
