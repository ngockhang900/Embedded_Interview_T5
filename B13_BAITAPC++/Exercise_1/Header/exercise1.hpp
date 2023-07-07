#ifndef __EXERCISE2_H
#define __EXERCISE2_H
#include <iostream>
#include <cmath>

using namespace std;

class Diem{
    private:
        int8_t coordinatesX;
        int8_t coordinatesY;
    public:
        Diem(int8_t x = 0, int8_t y = 0);
        void setCoordinatesX(int x);
        int8_t getCoordinatesX();
        void setCoordinatesY(int x);
        int8_t getCoordinatesY();
};

class PhepToanOXY{
    private:
        Diem diemA;
        Diem diemB;
        Diem diemC;
        typedef enum{
            KHOANG_CACH,
            DIEN_TICH_TAM_GIAC
        }TypePhepToan;
        TypePhepToan pheptoan;
    public:
        PhepToanOXY(Diem A, Diem B);
        PhepToanOXY(Diem A, Diem B, Diem C);
        float getKhoangCach();
        float getDienTich();
};

#endif