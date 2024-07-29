#include <iostream>
#include "complex.h"
using namespace std;
int main()
{
    Complex a(3.0,4.0);

    Complex c;
    cout<<"Enter a complex number (q to quit)"<<endl;

    while (cin>>c) // 这里用到了>>运算符重载
    {
         cout<<"c is"<<c;

         cout<<"complex conjugate is"<<~c;

         cout<<"a is"<<a;

         cout<<"a + c is"<<a+c;
         
         cout<<"a - c is"<<a-c;

         cout<<"a * c is"<<a*c;

         cout<<"2 *c is"<<2*c;

         cout<<"Enter a complex number (q to quit)"<<endl;
    }

    cout<<"Done"<<endl;
    return 0;
}