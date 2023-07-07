#include "exercise4.hpp"


int main()
{
    DongVat MEO("CAT",9,2.5);
    DongVat CHO("DOG",5, 3.3);
    cout<<"BMI: "<<MEO.soBMI()<<endl;
    cout<<"So sanh tuoi cua CAT va DOG: ";
    MEO.soSanhTuoi(CHO);
    cout<<"So sanh trong luong cua CAT va DOG: ";
    CHO.soSanhTrongLuong(MEO);
    return 0;
}