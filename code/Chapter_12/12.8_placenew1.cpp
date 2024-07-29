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
    // 这里其实的真正含义是我要开一块大小为512的空间，可以理解为内存池
    char *buffer= new char[BUF];

    // 这里只是声明了两个指向JustTesting对象的指针，并没有实际创建JustTesting对象
    JustTesting *pc1,*pc2;

    pc1=new(buffer) JustTesting; // 将对象放在buffer中
    pc2=new JustTesting("Heap1",20); // 将对象放在堆中

    // 由于buffer是char* 类型的，所以在输出地址的时候要加上强制类型转换
    cout<<"Memory block addersses:\n"<<"buffer:"<<(void *) buffer<<"   heap:"<<pc2<<endl;

    cout<<"Memory contents:\n";
    cout<<pc1<<":";
    pc1->Show();

    cout<<pc2<<":";
    pc2->Show();

    JustTesting *pc3,*pc4;
    pc3=new(buffer) JustTesting("Bad Idea",6);
    pc4=new JustTesting("heap2",10);

    cout<<"Memory contents:\n";
    cout<<pc3<<":";
    pc3->Show();

    cout<<pc4<<":";
    pc4->Show();

    delete pc2;
    delete pc4;
    delete[] buffer;
    cout<<"Done\n";
    return 0;


}