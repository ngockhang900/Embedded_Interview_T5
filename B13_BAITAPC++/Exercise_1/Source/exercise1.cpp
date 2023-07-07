#include "exercise1.hpp"



Diem::Diem(int8_t x, int8_t y){
    coordinatesX = x;
    coordinatesY = y;
}

void Diem::setCoordinatesX(int x){
    coordinatesX = x;
}

int8_t Diem::getCoordinatesX(){
    return coordinatesX;
}

void Diem::setCoordinatesY(int y){
    coordinatesY = y;
}

int8_t Diem::getCoordinatesY(){
    return coordinatesY;
}

PhepToanOXY::PhepToanOXY(Diem A, Diem B){
    pheptoan = KHOANG_CACH;
    diemA = A;
    diemB = B;
}
PhepToanOXY::PhepToanOXY(Diem A, Diem B, Diem C){
    pheptoan = DIEN_TICH_TAM_GIAC;
    diemA = A;
    diemB = B;
    diemC = C;
}
float PhepToanOXY::getKhoangCach(){
    if(pheptoan == KHOANG_CACH){
        int8_t x1 = diemA.getCoordinatesX();
        int8_t y1 = diemA.getCoordinatesY();
        int8_t x2 = diemB.getCoordinatesX();
        int8_t y2 = diemB.getCoordinatesY();
        return sqrt(pow(x2 - x1,2) + pow(y2 - y1, 2));
    }else{
        cout<<"Khong goi duoc ham tinh khoang cach";
        return 0;
    }
}

float PhepToanOXY::getDienTich(){
    if(pheptoan == DIEN_TICH_TAM_GIAC){
        int8_t x1 = diemA.getCoordinatesX();
        int8_t y1 = diemA.getCoordinatesY();
        int8_t x2 = diemB.getCoordinatesX();
        int8_t y2 = diemB.getCoordinatesY();
        int8_t x3 = diemC.getCoordinatesX();
        int8_t y3 = diemC.getCoordinatesY();
        return 0.5*abs((x2 - x1)*(y3 - y1)-(x3 - x1)*(y2 - y1));
    }else{
        cout<<"Khong goi duoc ham tinh dien tich tam giac";
        return 0;
    }
}
