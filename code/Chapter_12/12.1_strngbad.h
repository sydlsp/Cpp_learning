#include <iostream>
#ifndef STRINGBAD_H_
#define STRINGBAD_H_

class StringBad
{
    private:
        char *str; // string 指针
        int  len;// string 的长度

        // 采用静态类成员，无论创建多少个对象，程序都只创建一个静态变量副本，所有
        // 对象共享一个静态类成员，不能在类声明中初始化静态成员
        static int num_strings; //对象的数目，采用静态类成员
    
    public:
        StringBad(); // 默认构造函数
        StringBad(const char *s );
        ~StringBad();

        friend std::ostream & operator<<(std::ostream & os,const StringBad &st);
        
};

#endif