#include <iostream>
#include <string>

using namespace std;

class People{
    private:
        string name;
        uint16_t age;
        string address;
    public:
        void NhapThongTin();
        void InThongtin();
};

 void People::NhapThongTin(){
    string ten;
    string diaChi;
    int16_t tuoi;
    cout<<"Nhap ten: ";
    cin>>ten;
    cout<<"Nhap tuoi: ";
    cin>>tuoi;
    cout<<"Nhap dia chi: ";
    cin>>diaChi;
    name = ten;
    age = tuoi;
    address = diaChi;
 }

 void People::InThongtin(){
    cout<<"Ten: "<<name<<endl;
    cout<<"Tuoi: "<<age<<endl;
    cout<<"Dia chi: "<<address<<endl;
 }

 int main(int argc, char const *argv[])
 {
    People N;
    N.NhapThongTin();
    N.InThongtin();
    return 0;
    
 }
 