//
//  Sales_data.cpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/5/27.
//

#include "Sales_data.hpp"


// 在类外部定义构造函数
Sales_data::Sales_data(istream& is){
    read(is, *this);
}

double Sales_data::avg_price() const {
    return revenue / units_sold;
}

Sales_data& Sales_data::conbine(const Sales_data& s_d) {
    if (this->bookNo != s_d.bookNo) {
        return *this;
    }
    this->units_sold += s_d.units_sold;
    this->revenue += s_d.revenue;
    return *this;
}

Sales_data add(const Sales_data& a, const Sales_data& b) {
    Sales_data s_d(a);
    s_d.conbine(b);
    return s_d;
}

istream& read(istream& cin, Sales_data& s_d) {
    cout << "请依次输入：序列号、出售量、收入..." << endl;
    cin >> s_d.bookNo >> s_d.units_sold >> s_d.revenue;
    return cin;
}

ostream& print(ostream& cout, const Sales_data& s_d) {
    cout << "bn:" << s_d.isbn() << ",units_sold:" << s_d.units_sold << ",revenue:" << s_d.revenue;
    return cout;
}
