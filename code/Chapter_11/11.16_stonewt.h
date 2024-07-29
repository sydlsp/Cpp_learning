#ifndef STONEWE_H_
#define STONEWE_H_

class Stonewt
{
    private:
       enum {Lbs_per_stn=14};  //pounds per stone
       int stone;
       double pds_left;
       double pounds;
    
    public:
       Stonewt(double lbs);  // 初始化为一个浮点数，单位为磅
       Stonewt(int stn,double lbs); // 初始化为两个数字，分别代表英石和磅
       Stonewt();
       ~Stonewt();
       void show_lbs() const;
       void show_stn() const;
    

};
#endif