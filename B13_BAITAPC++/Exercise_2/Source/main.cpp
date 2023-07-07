#include "exercise2.hpp"

int main(int argc, char const *argv[])
{
    HinhChuNhat hcn;
    hcn.NhapChieuDai();
    hcn.NhapChieuRong();
    std::cout<<"Chu vi la: "<<hcn.ChuVi()<<std::endl;
    std::cout<<"Dien Tich la: "<<hcn.DienTich()<<std::endl;
    std::cout<<"Duong cheo la: "<<hcn.DuongCheo()<<std::endl;
    hcn.KiemtraHinhVuong();
    return 0;
}