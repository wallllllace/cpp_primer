//
//  TextQuery.cpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/6/2.
//

#include "TextQuery.hpp"
#include <sstream>
#include "QueryResult.hpp"

TextQuery::TextQuery(const vector<string>& txt): text(make_shared<vector<string>>(txt)){
    for (int i = 0; i < text->size() ; ++i) {
        istringstream line((*text)[i]);
        string word;
        while (line >> word) {
            auto &p = vm[word];
            if (!p) {
                p.reset(new set<int>);
            }
            p->insert(i);
        }
    }
}

QueryResult
TextQuery::query(const string& w) {
    auto p_set = vm[w];
    return QueryResult(p_set->size(), p_set, text);
}
