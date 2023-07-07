#ifndef __EXERCISE2_H
#define __EXERCISE2_H
#include <iostream>

class HinhChuNhat{
    private:
        uint8_t Chieu_dai;
        uint8_t Chieu_rong;
    public:
        void NhapChieuDai();
        void NhapChieuRong();
        uint16_t ChuVi();
        uint16_t DienTich();
        uint16_t DuongCheo();
        void KiemtraHinhVuong();
};

#endif