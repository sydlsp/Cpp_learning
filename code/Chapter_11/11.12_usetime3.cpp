#include <iostream>
#include "11.10_mytime3.h"
// 这里也是一样，头文件中已经include<iostream>了，其实不需要再在这里include了
// 但是为了代码的阅读性，需要负责的将编写代码所需要的头文件包含进来

int main()
{
    using std::cout;
    using std::endl;
    Time aida(3,35);
    Time tosca(2,48);
    Time temp;

    cout<<"Aida and Tosca"<<endl;
    cout<<aida<<";"<<tosca<<endl;

    temp=aida+tosca;
    cout<<"Aida+Tosca:"<<temp<<endl;

    temp=aida*1.17; //成员函数operator*
    cout<<"Aida*1.17"<<temp<<endl;

    cout<<"10.0*Tosca"<<10.0*tosca<<endl;

    return 0;
}