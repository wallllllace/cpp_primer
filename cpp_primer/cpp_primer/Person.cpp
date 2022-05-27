//
//  Person.cpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/5/27.
//

#include "Person.hpp"


Person::Person(istream &is) {
    read(is, *this);
}

istream& read(istream& cin, Person &p) {
    cin >> p.name >> p.addr;
    return cin;
}

ostream& print(ostream& cout, const Person &p) {
    cout << "name: " << p.name << ", address: " << p.addr;
    return cout;
}
