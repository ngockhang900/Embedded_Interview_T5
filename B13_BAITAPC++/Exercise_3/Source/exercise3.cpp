#include "exercise3.hpp"

void Circle::NhapBanKinh(){
    int16_t R;
    cout<<"Nhap ban kinh: ";
    cin>>R;
    Circle::radius = R;
}

double Circle:: ChuVi(){
    return 2*radius*3.14;
}

double Circle::DienTich(){
    return radius*radius*3.14;
}
