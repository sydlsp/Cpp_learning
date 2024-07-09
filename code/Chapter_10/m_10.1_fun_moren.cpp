#include <iostream>
using namespace std;
void test(int a,double b=100,char c='A');

int main()
{
    test(10);
    test(20,200,'B');
}
void test(int a,double b,char c)
{
    cout<<"a="<<a<<",b="<<b<<",c="<<c<<endl;
}