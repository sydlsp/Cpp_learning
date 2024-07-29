#include <iostream>
#include <string>
#include <new>

using namespace std;
const int BUF=512;

class JustTesting
{
     private:
       string words;
       int number;
    
    public:
       
       JustTesting(const string &s="Just Testing",int n=0)
       {
           // 这里注意，s是引用，但words是常规变量
           // 下面语句的含义是将s的值赋值给words而不是把words作为s的别名
           words=s;
           number=n;
           cout<<words<<" constructed\n";
       }

       // 析构函数
       ~JustTesting()
       {
           cout<<words<<" destroyed\n";
       }

       void Show() const;
};

void JustTesting::Show() const
{
      cout<<words<<","<<number<<endl;
}

int main()
{
    char *buffer=new char[BUF];

     JustTesting *pc1,*pc2;

     // 这里已经调用构造函数了
     pc1=new(buffer) JustTesting;
     pc2=new JustTesting("Heap1",20);

     cout<<"Memory block addersses:\n"<<"buffer:"<<(void *) buffer<<"   heap:"<<pc2<<endl;

    cout<<"Memory contents:\n";
    cout<<pc1<<":";
    pc1->Show();

    cout<<pc2<<":";
    pc2->Show();
    
    JustTesting *pc3,*pc4;
    // new定位到一个新地址
    pc3=new (buffer+sizeof(JustTesting)) JustTesting("Better idea",6);
    pc4=new JustTesting("Heap2",10);

    delete pc2;
    delete pc4;

    // 使用显式析构函数，这里还有一个小细节，由于pc1在pc3之前构造
    // 所以在析构的时候pc3应该在pc1之前析构
    pc3->~JustTesting();
    pc1->~JustTesting();
    delete[] buffer;
    cout<<"Done\n";
    return 0;

    
}