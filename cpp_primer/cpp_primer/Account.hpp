//
//  Account.hpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/5/29.
//

#ifndef Account_hpp
#define Account_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Account {
        // 静态数据类型的好处：1. 可以是不完全类型 2.可以做默认实参
public:
    
    Account( Account &a1 = a){} // 静态数据类型可以做默认实参,非静态数据类型不可以
    void calculate() { amount += amount * interestRate; }
    static double rate() { return  interestRate;}
    static void rate(double); // static 只能出现在类中，不能在类外定义中，静态函数不能使用const，没有this指针
    
private:
    string owner;
    double amount;
    static double interestRate;
    static double initRate(); // static 只能出现在类中，不能在类外定义中，静态函数不能使用const，没有this指针
    static Account a; // 静态数据类型可以是不完全类型
};


#endif /* Account_hpp */
