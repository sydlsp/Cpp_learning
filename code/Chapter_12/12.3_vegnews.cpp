#include <iostream>
using std::cout;
#include "12.1_strngbad.h"

void callme1(StringBad &); // 按引用传递
void callme2(StringBad); // 按值传递

int main()
{
    using std::endl;
    {
        cout<<"String an inner block"<<endl;
        StringBad headline1("Celery Stalks at Midnight");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spinach Leaves Bowl for Dollars");

        cout<<"headline1:"<<headline1<<endl;
        cout<<"headline2:"<<headline2<<endl;
        cout<<"sports:"<<sports<<endl;

        callme1(headline1);
        cout<<"headline1:"<<headline1<<endl;

        callme2(headline2);
        cout<<"headline2:"<<headline2<<endl;

        cout<<"Initialize one object to another"<<endl;
        StringBad sailor=sports;
        cout<<"sailor:"<<sailor<<endl;

        cout<<"Assign one object to another"<<endl;
        StringBad knot;
        knot=headline1;
        cout<<"knot:"<<knot<<endl;
        cout<<"Exiting the block"<<endl;
    }

    cout<<"End of main()"<<endl;
}

void callme1(StringBad &rsb)
{
    cout<<"String passed by reference:"<<rsb<<std::endl;
}

void callme2(StringBad sb)
{
    cout<<"String passed by value:"<<sb<<std::endl;
}