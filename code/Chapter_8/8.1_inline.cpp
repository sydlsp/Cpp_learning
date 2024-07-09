#include <iostream>

inline double square(double x); // 声明函数为内联函数

int main()
{

    using namespace std;

    double a,b;
    double c=3.0;

    a=square(5.0);
    b=square(4.5+7.5);


    cout<<a<<endl;
    cout<<b<<endl;
    cout<<square(c++)<<"  "<<c<<endl;


}

double square(double x)
{
    return x*x;
}