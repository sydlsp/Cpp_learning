#ifndef MYTIME0_H_
#define MYTIME0_H_

class Time
{
    private:
       int hours;
       int minutes;
    

    public:
      Time();
      Time(int h,int m=0);
      void AddMin(int m);
      void AddHr(int h);
      void Reset(int h=0,int m=0);
      // 成员函数可以访问类的所有对象的私有成员，这是C++语言设计的一部分
      // 这样的设计旨在允许类的成员函数可以完全控制和操作类的内部成员状态
      Time Sum(const Time &t) const;
      void Show() const;
};
#endif