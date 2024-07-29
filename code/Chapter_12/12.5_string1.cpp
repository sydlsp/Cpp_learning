#include <cstring>
#include "12.4_string.h"
using std::cin;
using std::cout;

// 初始化静态变量
int String::num_strings=0;


/*
静态函数
可以将成员函数声明为静态的，此时函数的声明必须包含关键字static
但是如果之后函数的定义是独立的，那么便不能包含关键字static

关于静态函数，不能通过对象调用静态成员函数，如果静态成员函数是在公有声明部分，可以用类名和作用域解析运算符来调用
同时，由于静态成员函数不与特定的对象相关联，因此只能使用静态数据成员
 */

int String::HowMany()
{
    return num_strings;
}

String::String(const char *s)
{
    len =std::strlen(s);
    str =new char [len+1];
    std::strcpy(str,s);
    num_strings++;
}

String::String()
{
    len=4;
    str=new char[1];// 之所以采用这种写法是为了和后面delete[]统一
    str[0]='\0';
    num_strings++;
}

// 复制构造函数
String::String(const String &st)
{
    num_strings++;
    len=st.len;
    str=new char [len+1];
    std::strcpy(str,st.str);
}

// 析构函数
String::~String()
{
    --num_strings;
    delete[] str;
}

// 赋值运算符重载
String& String::operator=(const String &st)
{    
     // 如果是自己给自己赋值，直接返回
    if (this==&st)
        return *this;
    
    delete[] str;//释放原来的new的内存
    len=st.len;
    str=new char [len+1];
    std::strcpy(str,st.str);
    return *this;
}

String & String::operator=(const char *s)
{
    delete [] str;
    len=std::strlen(s);
    str=new char[len+1];
    std::strcpy(str,s);
    return *this;
}

// 读和写非const字符串
// 看一下这两个函数的细节，对于[]运算符来言，city[0]那么第一个操作数是city，第二个操作数是0
// 之所以将返回类型定为引用，是因为这样便可以为特定元素赋值了
// 这两个函数并没有冲突，因为一个特征标是一个有const一个没有
// 这里要理解的一点是，虽然const形参可以接受非const实参，但是有没有const特征标是不一样的
char & String::operator[](int i)
{
    return str[i];
}

// 读const字符串
const char & String::operator[](int i) const
{
    return str[i];
}

// 友元函数
bool operator<(const String &st1,const String & st2)
{
    return (std::strcmp(st1.str,st2.str)<0);
}

bool operator>(const String &st1, const String &st2)
{
    return st2<st1;  // 用了上面重载的<号
}

bool operator==(const String &st1,const String &st2)
{
    return(std::strcmp(st1.str,st2.str)==0);
}

ostream& operator<<(ostream & os,const String &st)
{

    os<<st.str;
    return os;
}

istream& operator>>(istream &is,String &st)
{ 
    // 这里用String::CINLIM的主要原因我想是因为静态变量不属于任何一个实例
    // str可以直接使用的原因其实是str是this->str的简写，但静态变量是没有这种写法的，所以必须加上限定符
    char temp[String::CINLIM];
    is.get(temp,String::CINLIM);
    if (is)
        st=temp;// 这里是用到了上面重载的=运算符
    while (is && is.get()!='\n')
    {
           continue;
    }
    return is;
}
    
