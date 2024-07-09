#include<iostream>
#include "9.1_coordin.h"
using namespace std;

int main()
{
    rect rplace;
    polar pplace;

    cout<<"Enter the x and y values:"<<endl;

    while(cin>>rplace.x>>rplace.y)
    {
        pplace=rect_to_polar(rplace);
        show_polar(pplace);
        cout<<"Next two numbers(q)"
    }
}