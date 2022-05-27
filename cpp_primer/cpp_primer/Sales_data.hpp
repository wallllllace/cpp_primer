//
//  Sales_data.hpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/5/27.
//

#ifndef Sales_data_hpp
#define Sales_data_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Sales_data {
    friend istream& read(istream&, Sales_data&);
    friend ostream& print(ostream&, const Sales_data&);
    
    string bookNo; // bn号， string不是内置类型，可以不用定义一个初始值
    unsigned units_sold = 0; // 出售数量，内置类型要定义一个初始值，否则值是未定义的
    double revenue = 0.0; // 收入，内置类型要定义一个初始值，否则值是未定义的
    
public:
    Sales_data() = default;
    Sales_data(const string& no): bookNo(no) { }
    Sales_data(const string& no, unsigned u_sold, double p): bookNo(no), units_sold(u_sold), revenue(u_sold * p) {}
    Sales_data(istream& is); // 此处仅是声明，在类外部定义
    inline string isbn() const {return bookNo;} // 定义在类内部的函数是隐式inline，不用写inline
    Sales_data& conbine(const Sales_data&);
    double avg_price() const; // 平均单价
};

Sales_data add(const Sales_data&, const Sales_data&); // 返回this对象的函数
istream& read(istream&, Sales_data&);
ostream& print(ostream&, const Sales_data&);

#endif /* Sales_data_hpp */
