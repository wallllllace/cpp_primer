//
//  TextQuery.hpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/6/2.
//

#ifndef TextQuery_hpp
#define TextQuery_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>

using namespace std;

class QueryResult;
class TextQuery {
    
public:
    TextQuery(const vector<string>& txt);
    QueryResult query(const string& w);
    
private:
    // vector 保存所有行的文本
    // map key是要查询的单词，value是set，set中保存着单词出现的行号，升序排列
    
    shared_ptr<vector<string>> text;
    map<string, shared_ptr<set<int>>> vm;
    
};

#endif /* TextQuery_hpp */
