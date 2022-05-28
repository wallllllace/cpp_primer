//
//  Account.cpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/5/29.
//

#include "Account.hpp"

double Account::interestRate = initRate(); // 静态成员变量的定义可以写在这里

void Account::rate(double newRate) { // static 只能出现在类中，不能在类外
    interestRate = newRate;
}

double Account::initRate() { // static 只能出现在类中，不能在类外
    return interestRate;
}




