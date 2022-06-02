//
//  QueryResult.cpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/6/2.
//

#include "QueryResult.hpp"


void QueryResult::print(ostream& os) {
    os << "element occurs " << count << " times" << endl;
    for (auto& i : *lines) {
        auto t = (*text)[i];
        os << "line(" << i << ")" <<  t << endl;
    }
}
