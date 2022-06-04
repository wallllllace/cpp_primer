//
//  Employee.hpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/6/3.
//

#ifndef Employee_hpp
#define Employee_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Employee {
public:
    Employee();
    Employee(const string &name);
    Employee(const Employee&) = delete;
    Employee& operator=(const Employee&) = delete;

    const int id() const { return id_; }

private:
    string name_;
    int id_;
    static int s_increment;
};

#endif /* Employee_hpp */
