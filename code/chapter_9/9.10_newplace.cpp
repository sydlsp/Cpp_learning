#include <iostream>
#include <new>

const int BUF = 512;
const int N = 5;

char buffer[BUF];

int main()
{
    using namespace std;

    double *pd1, *pd2;
    int i;
    cout << "Calling new and placement new:" << endl;
    pd1=new double[N]; // 使用堆
    pd2=new(buffer) double [N]; // 使用buffer数组的地址

    for (int i=0;i<N;i++)
        pd2[i]=pd1[i]=1000+20.0*i;
    
    cout<<"Memory addresses:"<<endl;
    // 这里复习一下当buffer是指向char的指针的时候，想输出其地址要加上(void *)强制转换
    cout<<"heap:"<<pd1<<"   static:"<<(void *)buffer<<endl;
    cout<<"new pd2:"<<pd2;

    for (i=0;i<N;i++)
    {
        cout<<pd1[i]<<" at "<<&pd1[i]<<"; ";
        cout<<pd2[i]<<" at "<<&pd2[i]<<endl;
    }

    cout<<"Calling new and placement new a second time:"<<endl;
    double *pd3, *pd4;
    pd3=new double[N]; // 还是使用堆,找到新的地址
    pd4=new(buffer) double[N]; // 使用buffer数组的地址，这里是覆写之前的内容了
    
    for (int i=0;i<N;i++)
        pd4[i]=pd3[i]=1000+40.0*i;
    
    cout<<"Memory contents"<<endl;
    for (i=0;i<N;i++)
    {
        cout<<pd3[i]<<" at "<<&pd3[i]<<"; ";
        cout<<pd4[i]<<" at "<<&pd4[i]<<endl;

    }


    // 释放内存
    delete [] pd1;
    delete [] pd3;
    return 0;

}