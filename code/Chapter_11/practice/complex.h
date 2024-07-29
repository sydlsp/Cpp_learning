#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>
using namespace std;
//定义复数类
class Complex
{
    private:
       double a;
       double b;//定义实部和虚部

    public:
       Complex();// 默认构造函数
       Complex(double in_a,double in_b);

       // 在复数的相关运算中涉及到加减乘除取共轭等操作
       // 乘法涉及到两个复数相乘以及复数与实数相乘

       // 取共轭复数，记住：运算符函数作为类的成员时，第一个操作数就是自己
       Complex operator~() const;

       // 下面复数之间的加减法以及乘法，由于两个操作数都是Complex类
       // 为了进一步熟悉类的相关知识
       // 将加减法的运算符函数设置为类成员函数，乘法的运算符函数设置为友元，来体验两种方法

       // op2强调了第一个操作数是自己，使用引用的原因还是类的数据量大，用引用开销相对较小
       // 用const限制函数不能修改原有的两个操作数
       Complex operator+(const Complex & op2) const;
       Complex operator-(const Complex & op2) const;
       friend Complex operator*(const Complex &op1,const Complex &op2); 

       // 复数与整数的相乘，在题目中要求第二个操作数是复数，因此只能用友元
       friend Complex operator* (double num,const Complex &op2);

       // 重载<<运算符
       friend std::ostream & operator<<(std::ostream &os,const Complex &op1);

       // 重载>>运算符，这里我们是要输入，要修改值，不要加const限定
       friend std::istream & operator>>(std::istream &is,Complex &op1);

};
#endif