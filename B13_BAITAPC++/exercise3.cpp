#include <iostream>


using namespace std;

class Circle{
    private:
        int16_t radius;
    public:
        void NhapBanKinh();
        double ChuVi();
        double DienTich();
};

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

int main(int argc, char const *argv[])
{
    Circle ht;
    ht.NhapBanKinh();
    cout<<"Chu vi hinh tron la: "<<ht.ChuVi()<<endl;
    cout<<"Dien tich hinh tron la: "<<ht.DienTich()<<endl;
    return 0;
}
