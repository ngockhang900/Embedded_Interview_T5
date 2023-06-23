#include <iostream>
#include <string>
using namespace std;


class Student{
    // private:
    //     string name;  // property
    //     int16_t age;

/*  Vì private nó chỉ có giá trị trong Class chứa nó tức là chỉ có Class Student mới có thể trỏ đến private được thôi kế thừa cũng không sử dụng được
    Nên ta dùng protected để cho phép Class kế thừa sử dụng được các thuộc tính */
    protected:
        string name;
        int16_t age;
    public:
        void desplay(); // method
        void MoreInformation(string ten, int tuoi);
};

void Student::desplay(){
    cout<<"Day la Class Student\n";
    cout<<"Ten: "<<name<<endl;
    cout<<"Tuoi: "<<age<<endl;
}

void Student::MoreInformation(string ten, int tuoi){
    Student::name = ten; 
    Student::age = tuoi;
}

// Class SnhVien inheritance public Class Student. Can override
class SinhVien : public Student{
    public:
        SinhVien(string ten, int8_t tuoi, int mssv ); // Constructor can have an input parameter or not input paremeter
        void desplay();
    private:
        int MSSV;
};

SinhVien::SinhVien(string ten, int8_t tuoi, int mssv){
    name = ten;
    age = tuoi;
    MSSV = mssv;
}

void SinhVien::desplay(){
    cout<<"Day la Class SinhVien\n";
    cout<<"Ten: "<<name<<endl;
    cout<<"Ten: "<<age<<endl;
    cout<<"Ten: "<<MSSV<<endl;
}




int main(int argc, char const *argv[])
{
    Student A;  // Object A
    A.MoreInformation("khang",23);
    A.desplay();

    //use constructor
    SinhVien B("hoang",23, 1851);
    B.desplay();
    
    return 0;
}

