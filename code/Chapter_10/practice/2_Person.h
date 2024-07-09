#include <string>

class Person
{
    private:
       static const int LIMIT=25; // 静态变量，不属于任何类
       std::string lname; // last name
       char fname[LIMIT];// first name
    
    public:
       // 默认构造函数
       Person() {lname="",fname[0]='\0';} 
       // 重载的构造函数
       Person(const std::string &ln,const char * fn="Heyyou");
       void Show() const;
       void FormalShow() const;
};