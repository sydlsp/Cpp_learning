#include<iostream>
using namespace std;

typedef int* intp;

int main()
{
    int *a,b;
    intp c,d;

    cout<<typeid(a).name()<<endl;
    cout<<typeid(b).name()<<endl;
    cout<<typeid(c).name()<<endl;
    cout<<typeid(d).name()<<endl;
}