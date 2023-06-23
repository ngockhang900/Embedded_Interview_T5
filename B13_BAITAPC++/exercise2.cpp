#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

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

int main(int argc, char const *argv[])
{
    HinhChuNhat hcn;
    hcn.NhapChieuDai();
    hcn.NhapChieuRong();
    cout<<"Chu vi la: "<<hcn.ChuVi()<<endl;
    cout<<"Dien Tich la: "<<hcn.DienTich()<<endl;
    cout<<"Duong cheo la: "<<hcn.DuongCheo()<<endl;
    hcn.KiemtraHinhVuong();
    return 0;
}