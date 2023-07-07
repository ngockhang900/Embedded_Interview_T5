#include "exercise4.hpp"


DongVat::DongVat(string ten, uint8_t tuoi, double trongLuong){
    this->ten = ten;
    this->tuoi = tuoi;
    this->trongLuong = trongLuong;
}

double DongVat::soBMI(){
    double chieucao = 1.5;
    return trongLuong/(chieucao*chieucao);
}
void DongVat::soSanhTuoi(const DongVat &DVkhac){
    if(tuoi < DVkhac.tuoi){
        cout<<"Tuoi cua "<<ten<<" nho hon tuoi cua "<<DVkhac.ten<<endl;
    }else{
        cout<<"Tuoi cua "<<ten<<" lon hon tuoi cua "<<DVkhac.ten<<endl;
    }
}
void DongVat::soSanhTrongLuong(const DongVat &DVkhac){
    if(trongLuong < DVkhac.trongLuong){
        cout<<"Trong luong cua "<<ten<<" nho hon trong luong cua "<<DVkhac.ten<<endl;
    }else{
        cout<<"Trong luong cua "<<ten<<" lon hon trong luong cua "<<DVkhac.ten<<endl;
    }
}

