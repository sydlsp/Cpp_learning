#include <iostream>

// 模板函数声明
template<class T> void Swap(T &,T &);

struct job
{
    char name[40];
    double salary;
    int floor;
};

// 显式具体化函数声明
template<> void Swap<job> (job &,job &);

void Show(job & j);

int main()
{

    using namespace std;

    cout.precision(2);
    cout.setf(ios::fixed,ios::floatfield);

    int i=10,j=20;
    cout<<"i,j="<<i<<","<<j<<endl;

    // 使用通用模板
    Swap(i,j);
    cout<<"Now i,j="<<i<<","<<j<<endl;

    job sue={"Susan Yaffee",73000.60,7};
    job sidney={"Sidney Taffee",78060.72,9};

    cout<<"Before swapping"<<endl;
    Show(sue);
    Show(sidney);

    // 用显式具体化函数
    Swap(sue,sidney);
    cout<<"After swapping"<<endl;
    Show(sue);
    Show(sidney);
    return 0;
}

template<class T> void Swap(T &a,T &b)
{
    T temp;
    temp=a;
    a=b;
    b=temp;
}

template<> void Swap<job> (job &a,job &b)
{
    double t1;
    int t2;

    t1=a.salary;
    a.salary=b.salary;
    b.salary=t1;

    t2=a.floor;
    a.floor=b.floor;
    b.floor=t2;
}

void Show(job &a)
{
    using namespace std;
    cout<<a.name<<"$"<<a.salary<<"On floor"<<a.floor<<endl;
}