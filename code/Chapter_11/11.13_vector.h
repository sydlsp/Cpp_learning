#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
namespace VECTOR
{
    class Vector
    {
        public:
           enum Mode {RECT,POL}; //这里其实是定义了两种矢量的表示形式
           
        private:
           double x;
           double y;
           double mag;
           double ang;
           Mode mode;
           void set_mag();
           void set_ang();
           void set_x();
           void set_y();
        
        public: 
           Vector();
           Vector(double n1,double n2,Mode form=RECT);
           void reset(double n1,double n2,Mode form=RECT);
           ~Vector();
           double xval() const {return x;}// 报告x值
           double yval() const {return y;}// 报告y值
           double magval() const {return mag;}
           double angval() const {return ang;}
           void polar_mode();
           void rect_mode();

           // 操作符重载
           Vector operator+(const Vector &b) const;
           Vector operator-(const Vector &b) const;
           Vector operator-() const;
           Vector operator*(double n) const;

           //友元函数，记住只有在声明的时候需要friend，在定义的时候不需要加friend
           friend Vector operator*(double n,const Vector &a);
           friend std::ostream & operator<<(std::ostream &os,const Vector &v);


    };
}
#endif