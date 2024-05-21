#include <iostream>
#include <cxxabi.h>
using namespace std;
int main()
{
    int temp[4][5];
    
    cout<<temp[0]<<endl;
    cout<<abi::__cxa_demangle(typeid(temp[0]).name(),0,0,0 )<<endl;
}