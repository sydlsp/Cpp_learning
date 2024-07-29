#include <iostream>
#include "complex.h"

using namespace std;
// 默认构造函数
Complex::Complex()
{
    a=b=0;
}

Complex::Complex(double in_a,double in_b)
{
    a=in_a;
    b=in_b;
}

// 这里一定要分清了第一个Complex是返回类型，第二个Complex是表示operator~是Complex类中的成员
Complex Complex::operator~() const
{
   Complex temp;
   temp.a=a;
   temp.b=-b;
   return temp;
}

Complex Complex::operator+(const Complex & op2) const
{
    Complex temp;
    temp.a=a+op2.a;
    temp.b=b+op2.b;
    return temp;
}

Complex Complex::operator-(const Complex &op2) const
{
   Complex temp;
   temp.a=a-op2.a;
   temp.b=b-op2.b;
   return temp;
}

// 由于之前在类声明中声明乘法是友元
// 这里具体实现的时候不需要加friend，因为决定谁是友元函数是类的事情，不是这个函数本身可以决定的
// 这里的Complex是返回类型，由于友元函数不是类的成员，因此，不需要加限定域
Complex operator*(const Complex &op1,const Complex &op2)
{
     Complex temp;
     temp.a=op1.a*op2.a-op1.b*op2.b;
     temp.b=op1.a*op2.b+op1.b*op2.a;
     return temp;
}

Complex operator*(double num,const Complex & op1)
{
     Complex temp;
     temp.a=num*op1.a;
     temp.b=num*op1.b;
     return temp;
}

// 重载<<运算符，之所以要用友元函数的原因再复习一下
// <<运算符要求第一个操作数是ostream类型
ostream & operator<<(ostream& os,const Complex &op1)
{
    cout<<"The Complex is"<<endl;
    if (op1.b==0)
       cout<<op1.a<<endl;
    else if (op1.b<0)
    {
        cout<<op1.a<<op1.b<<"i"<<endl;
    }

    else
       cout<<op1.a<<"+"<<op1.b<<"i"<<endl;
    
    return os;
    
}

// 重载>>运算符
istream& operator>>(istream & is,Complex &op1)
{
    cout<<"Please enter a and b"<<endl;
    double a,b;
    cin>>a>>b;
    op1.a=a;
    op1.b=b;
    return is;
}