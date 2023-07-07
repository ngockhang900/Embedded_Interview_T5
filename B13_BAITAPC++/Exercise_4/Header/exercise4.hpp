#ifndef __EXERCISE4_H
#define __EXERCISE4_H

#include <iostream>
#include <string>

using namespace std;

class DongVat{
    private:
        string ten;
        uint8_t tuoi;
        double trongLuong;
    public:
        DongVat(string ten, uint8_t tuoi, double trongLuong);
        double soBMI();
        void soSanhTuoi(const DongVat &DVkhac);
        void soSanhTrongLuong(const DongVat &DVkhac);
};

#endif