//
//  Person.hpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/5/27.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Person {
    friend istream& read(istream&, Person &);
    friend ostream& print(ostream&, const Person &);
    string name;
    string addr;
    
public:
    Person() = default;
    Person(const string& n): name(n){}
    Person(const string& n, const string& a): name(n), addr(a) {}
    explicit Person(istream &);
    string myName() const { return name; }
    string myAddr() const { return addr; }
};

istream& read(istream&, Person &);
ostream& print(ostream&, const Person &);

#endif /* Person_hpp */
