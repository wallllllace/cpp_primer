//
//  QueryResult.hpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/6/2.
//

#ifndef QueryResult_hpp
#define QueryResult_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

class QueryResult {
    
public:
    friend class TextQuery;
    
    QueryResult(int c, shared_ptr<set<int>> l, shared_ptr<vector<string>> txt): count(c), text(txt), lines(l) { };
    void print(ostream& os);
    
private:
    int count;
    shared_ptr<vector<string>> text;
    shared_ptr<set<int>> lines;
};

#endif /* QueryResult_hpp */
