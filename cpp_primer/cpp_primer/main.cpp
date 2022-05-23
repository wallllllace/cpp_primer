//
//  main.cpp
//  cpp_primer
//
//  Created by wangxiaorui19 on 2022/5/22.
//

#include <iostream>
//#include <cctype>

#include <vector>

using namespace std;


//string global_str;
//int global_int;

extern int ix = 1024; // 定义
int iy; // 定义
extern int iz; // 声明

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    /*
     // 练习2.3
     unsigned u = 10, u2 = 42;
     cout << u2 - u << endl; // 32
     cout << u - u2 << endl; // 很大的数
     
     int i = 10, i2 = 42;
     cout << i2 - i << endl; // 32
     cout << i - i2 << endl; // -32
     cout << i - u << endl; // 0
     cout << u - i << endl; // 0
     cout << i - u2 << endl; // 很大的数
     cout << u2 - i << endl; // 32
     */
    
//    cout << "F\145rgus?\012" << endl;
    
//    cin >> int input_value; / /报错
//
//    int i1 = {3.14}; // 这两种不可以（类型不同）,意义相同
//    int i2{3.14};
//    int i3(3.14); // 这两种可以，意义相同
//    int i4 = 3.14;
    
    
//    int local_int;
//    string local_str;
//
//    cout << global_str << endl; // 默认初始化为空字符串
//    cout << global_int << endl; // 默认初始化为0，xcode没有警告（内置类型定义在函数体之外，未被初始化的会默认初始化为0）
//    cout << local_int << endl; // 内置类型在函数内定义，不会默认初始化，值是未定义的，xcode发出警告
//    cout << local_str << endl; // 非内置类型在函数内定义，会被初始化
    
//    int ival = 1.01; // 合法
//    int &ival1 = 1.01; // 不合法
//    int &ival2 = ival; // 合法
//    int &ival3; // 不合法
    
//    int i = 0, &r1 = i;
//    double d = 0, &r2 = d;
//
//    r2 = 3.14159;
//    r2 = r1;
//    i = r2;
//    r1 = d;
    
//    int i, &ri = i;
//    i = 5, ri = 10;
//
//    cout << i << " " << ri <<endl;
    
//    int a = 10;
//    int *p = &a;
//    cout << "p:" << p << endl;
//    cout << "*p:" << *p << endl;
//
//    *p = 11; // 修改指针指向的值
//    cout << "p:" << p << endl;
//    cout << "*p:" << *p << endl;
//
//    int b = 10;
//    p = &b; // 修改指针的值
//    cout << "p:" << p << endl;
//    cout << "*p:" << *p << endl;
    
    
//    int i = 42;
//    int *p1 = &i; // p1向i
//    *p1 = *p1 * *p1; // p1指向的值相乘，结果赋值给p1指向的值
    
//    int i = 0;
//    double *dp = &i; // 非法，类型不同，不能赋值
//    int *ip = i; // 非法，类型不同，int 型 赋值给 int *型
//    int *p = &i; // 正常
    
//    int *p;
//    if (p) {
//        // 如果不是空指针执行
//    }
//    if (*p) {
//        // 如果p指向的值不是0执行
//    }
    
//    int *ip, i, &r = i; // ip未初始化的指针指向不确定，在xcode中被初始化为0了
//    cout << "ip:" << ip <<endl;
//    cout << "i:" << i <<endl;
//    cout << "r:" << r <<endl;
    
//    const int buf; // const 必须初始化
//    int cnt = 0;
//    const int sz = cnt;
//    ++cnt;
//    ++sz; // const 不能更改
    
//    double dval = 3.14;
//    const int &ri = dval;
//    cout << "ri:" << ri <<endl;
    
//    int i = -1, &r = 0; // 不合法，r不能绑定到一个字面量
//    int i2 = 10;
//    int *const p2 = &i2; //合法，常量指针，p2不能修改，但是p2指向的值可以修改
//    const int i = -1, &r = 0; // 合法，常量引用可以引用字面量
//    const int * const p3 = &i2; // 合法，常量指针常量
//    const int *p1 = &i2; // 合法，指针常量
//    const int &const r2; // 不合法，引用不是类型
//    int  i = 10;
//    const int i2 = i, &r = i; //合法，常量引用可以应用非常量
    
//    const int v2 = 0; int v1 = v2; // 顶层const，拷贝不受影响
//    int *p1 = &v1, &r1 = v1; // 不是const
//    int i = 0;
//    const int *p2 = &v2, * const p3 = &i, &r2 = v2; // 第二个顶层const忽略，底层const可以转化
//
//    r1 = v2; // 错误
//    p1 = p2; // 错误，底层const赋值给非const
//    p2 = p1; // 正确，底层const可以转化
//    p1 = p3; // 错误
//    p2 = p3; // 正确，顶层const忽略，底层const相同
    
//    string a("a");
//    string b{"b"};
//    string c(10,'c');
//
//    cout << "a:" << a << endl;
//    cout << "b:" << b << endl;
//    cout << "c:" << c << endl;
//    string s1;
//    string s2;
//    while (getline(cin, s)) {
//        cout << "s:" << s <<endl;
//    }
//    while (cin >> s1 >> s2) {
//        if (s1.size() == s2.size()) {
//            cout << "s1和s2等长" << endl;
//        } else {
//            cout << "s1和s不等长" << endl;
//            string tmp = s1.size() > s2.size() ? s1 : s2;
//            cout << "两者中较长的是：" << tmp << endl;
//        }
//
//    }
//    string r_str;
//    string s;
//    while (cin >> s) {
//        r_str += s;
//        r_str += " ";
//    }
//    cout << "最后的字符串是：" << r_str << endl;
    
//    string s = "string";
//    for (char &c : s) {
//        c = 'X';
//    }
//    cout << "s:" << s << endl;
    
//    vector<vector<int>> ivec; // 正确的
//    vector<string> svec = ivec; // 不正确，类型不同
//    vector<string> svec(10, "null"); // 正确的
    
//    vector<int> v1; // 0个元素
//    vector<int> v2(10); // 10个0
//    vector<int> v3(10,42); // 10个42
//    vector<int> v4{10}; // 1个10
//    vector<int> v5{10,42}; // 2个 10、42
//    vector<string> v6{10}; // 10 个 “”
//    vector<string> v7{10, "hi"}; // 10 个 “hi”
    
//    for (auto item : v6) {
//        cout << item << endl;
//    }
    
//    string s = "a";
//    auto it = v3.cend();
//    cout << *it << endl;
    
    
//    vector<string> v;
//    string s;
//    while (cin >> s) {
//        v.push_back(s);
//    }
//
//    for (auto &item : v) {
//        for (auto &c : item) {
//            c = toupper(c);
//        }
//    }
//    for (auto item : v) {
//        cout << item << endl;
//    }
    
    
//    vector<int> v1(10, 42);
//    vector<int> v2{42,42,42,42,42,42,42,42,42,42};
//    vector<int> v3(v1);
    
    
    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num);
    }
  
//    int i = 0;
//    while (i < nums.size()) {
//        int sum = nums[i];
//        if (i+1<nums.size()) {
//            sum += nums[i+1];
//        }
//        i += 2;
//        cout << sum << endl;
//    }
    
    vector<int>::size_type i = 0, j = nums.size()-1;
    while (i <= j) {
        int sum = nums[i];
        if (i < j) {
            sum = nums[i] + nums[j];
        }
        ++i;
        --j;
        cout << sum << endl;
     }

    return 0;
}
