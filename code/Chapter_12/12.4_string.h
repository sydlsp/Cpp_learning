#ifndef STRING_1_
#define STRING_1_

#include <iostream>
using std::ostream;
using std::istream;

class String
{
    private:
        char *str;
        int len;
        // static const 可以在类定义的时候就赋值
        // 但是其他静态变量不可以
        static int num_strings;
        static const int CINLIM=80;
    
    public:
       String(const char *s);
       String();
       String(const String &);// 复制构造函数
       ~String();
       // 内联函数
       int length() const {return len;}

       // 运算符重载函数
       String & operator=(const String & s);
       String & operator=(const char *s);
       char & operator[](int i);
       const char & operator[](int i) const;

       //友元函数
       friend bool operator<(const String &st1,const String &st2);
       friend bool operator>(const String &st1,const String &st2);
       friend bool operator==(const String &st1,const String &st2);
       friend ostream & operator<<(ostream &os,const String &st1);
       friend istream & operator>>(istream & is, String & st1);

       //静态函数
       static int HowMany();
};
#endif