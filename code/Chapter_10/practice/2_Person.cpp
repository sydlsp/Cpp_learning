#include <iostream>
#include "2_Person.h"

Person::Person(const std::string &ln,const char * fn)
{
    lname=ln;
    int i=0;
    while (fn[i]!='\0')
    {
        fname[i]=fn[i];
        i++;
    }
    fname[i]='\0';
}

void Person::Show() const
{
    using namespace std;
    cout<<fname<<"  "<<lname<<endl;
}

void Person::FormalShow() const
{
    using namespace std;
    cout<<lname<<"  "<<fname<<endl;
}