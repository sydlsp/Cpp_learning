#ifndef COORDIN_H
#define COORDIN_H


struct polar
{
    double distance;
    double angle;
};

struct rect
{
    double x;
    double y;
};


// 函数原型
polar rect_to_polar(rect xypos);

void show_polar(polar dapos);

#endif
