#include <iostream>
using namespace std;

int main()
{
    int updates=6;
    int *p_updates; //声明int型指针

    p_updates=&updates; //将update的地址给p_updates

    cout<<p_updates<<endl; //输出地址
    cout<<*p_updates; //用*运算符来取地址中的值
}