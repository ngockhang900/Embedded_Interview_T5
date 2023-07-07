#include <iostream>
#include <math.h>
#include "exercise2.hpp"

using namespace std;



void HinhChuNhat::NhapChieuDai(){
    int dai;
    cout<<"Nhap chieu dai: ";
    cin>>dai;
    Chieu_dai = dai;
}

void HinhChuNhat::NhapChieuRong(){
    int rong;
    cout<<"Nhap chieu rong: ";
    cin>>rong;
    Chieu_rong = rong;
}

uint16_t HinhChuNhat::ChuVi(){
    return 2*(Chieu_dai + Chieu_rong);
}

uint16_t HinhChuNhat::DienTich(){
    return (Chieu_dai * Chieu_rong);
}

uint16_t HinhChuNhat::DuongCheo(){
    return sqrt((Chieu_dai*Chieu_dai) + (Chieu_rong*Chieu_rong));
}

void HinhChuNhat::KiemtraHinhVuong(){
    if (Chieu_dai == Chieu_rong)
    {
        cout<<"La hinh vuong";
    }else{
        cout<<"Khong phai la hinh vuong";
    }
    
}

