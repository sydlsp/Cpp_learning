#include <cstring>
#include "12.1_strngbad.h"
using std::cout;

// 这里要注意了，对于静态成员要在类之外使用单独的语句进行初始化
// 即使num_lengths是private成员也是用这种方式初始化
// 但是，这样并不是说可以用STRNG::num_length来访问静态成员
// 同时，在初始化的时候不需要使用关键字static
int StringBad::num_strings=0;

StringBad::StringBad(const char *s)
{
      len=std::strlen(s);
      str=new char [len+1];
      // 注意：不能写str=s,这样只是保存了地址，没有创建字符串副本
      std::strcpy(str,s);
      num_strings++;
      cout<<num_strings<<":"<<std::endl<<str<<std::endl<<"object create";
} 

StringBad::StringBad()
{
    len=4;
    str=new char [4];
    std::strcpy(str,"C++");
    num_strings++;
    cout<<num_strings<<":"<<std::endl<<str<<std::endl<<"object create";
}

// 析构函数
StringBad::~StringBad()
{
    cout<<std::endl<<str<<std::endl<<"object deleted";
    --num_strings;
    cout<<num_strings<<"left"<<std::endl;
    // 删除对象可以释放对象本身占用的内存，但是并不能自动释放属于对象成员的指针指向的内存
    // 在这里，必须在析构函数中用delate来释放内存
    delete [] str;
}

std::ostream& operator<<(std::ostream &os ,const StringBad &st)
{
    cout<<st.str;
    return os;
}