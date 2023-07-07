#include "exercise5.hpp"

 void People::InThongtin(){
    cout<<"Ten: "<<name<<endl;
    cout<<"Nam Sinh: "<<year<<endl;
    cout<<"Dia chi: "<<address<<endl;
 }

int People::TinhTuoi() {
        time_t now = time(0);
        tm* localTime = localtime(&now);
        int NamHienTai = localTime->tm_year + 1900;
        return NamHienTai - year;
}


 