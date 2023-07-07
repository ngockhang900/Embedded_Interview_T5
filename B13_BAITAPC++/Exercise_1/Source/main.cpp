#include "exercise1.hpp"


int main()
{
    Diem A(2,3);
    Diem B(4,6);
    Diem C(7,8);

    PhepToanOXY pheptoan1(A, B);
    float khoangcach = pheptoan1.getKhoangCach();
    cout<<"Khoang cach hai diem: "<<khoangcach<<endl;

    PhepToanOXY pheptoan2(A, B, C);
    cout<<"Dien tich tam giac: "<<pheptoan2.getDienTich()<<endl;
    return 0;
}
