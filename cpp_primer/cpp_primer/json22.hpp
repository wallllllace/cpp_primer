//
//  json22.hpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/6/6.
//

#ifndef json22_hpp
#define json22_hpp

#include <stdio.h>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <initializer_list>

using namespace std;

namespace json22 {

class Value;
class Json {
    
public:
    typedef std::vector<Json> Array;
    typedef std::map<string, Json> Object;
    
    Json() = delete;
    
    Json(int);
    Json(bool);
    Json(const std::string&);
    Json(std::string&&);
    Json(const Array&);
    Json(Array&&);
    Json(const Object&);
    Json(Object&&);
    Json(const Json&);
    Json(Json&&);
    
    void dump(std::string &out) const;
    std::string dump() const {
        std::string out;
        dump(out);
        return out;
    }

private:
    shared_ptr<Value> ptr;
};

class Value {
    
public:
    virtual void dump(string&) = 0;
    
};


}

#endif /* json22_hpp */
