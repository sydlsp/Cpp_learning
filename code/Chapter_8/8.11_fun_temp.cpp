#include <iostream>

// 函数模板原型
template <typename T> // or class T
void Swap(T & a, T & b);

int main()
{
    using namespace std;

    int i=10,j=20;
    cout<<"i:"<<i<<"j:"<<j;

    Swap(i,j);// 生成void Swap(int &,int &)
    cout<<"i:"<<i<<"j:"<<j;

    double x=24.5,y=81.7;
    cout<<"x:"<<x<<"y:"<<y;
    Swap(x,y);
    cout<<"x:"<<x<<"y:"<<y;

}

template <typename T>
void Swap(T & a, T & b)
{
    T temp;
    temp=a;
    a=b;
    b=temp;
}