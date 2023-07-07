#ifndef __EXERCISE10_H
#define __EXERCISE10_H


#include <iostream>
#include <string>


class Sach{
    private:
        std::string tenSach;
        std::string tacGia;
        int XuatBan;
        int SoLuong;
    public:
        Sach(std::string tenSach, std::string tacGia, int XuatBan, int SoLuong = 1)
        : tenSach(tenSach), tacGia(tacGia), XuatBan(XuatBan),SoLuong(SoLuong) {}
        void InThongTin();
        void MuonSach();
        void TraSach();
};

#endif