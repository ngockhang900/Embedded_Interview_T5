#include <iostream>
#include <list>
#include <string>

#define PROMPT_OPTION \
    int x; \
    do { \
        cout << "Chuong trinh goi mon\n"; \
        cout << "1. Quan Ly\n"; \
        cout << "2. Nhan Vien\n"; \
        cout << "Vui long nhap vao:..."; \
        cin >> x; \
    } while (x != 1 && x != 2)


using namespace std;

class MonAn{
    private:
        uint8_t ID;
        string TEN;
        double GIA;
    public:
        MonAn(string ten, double gia);
        uint8_t getID();
        void setTen();
        string getTen();
        void setGia();
        double getGia();
};

MonAn::MonAn(string ten, double gia) {
    static uint8_t counter = 0;
    ID = counter++;
    TEN = ten;
    GIA = gia;
}

uint8_t MonAn::getID() {
    return ID;
}

void MonAn::setTen() {
    cout << "Nhap ten mon an: ";
    cin >> TEN;
}

string MonAn::getTen() {
    return TEN;
}

void MonAn::setGia() {
    cout << "Nhap gia mon an: ";
    cin >> GIA;
}

double MonAn::getGia() {
    return GIA;
}

class QuanLy{
    private:
        list<MonAn> DATABASE;
        uint8_t SO_BAN;
        void themMon();
        void suaMon();
        void xoaMon();
        void danhSachMon();
        void thietLapSoBan();
    public:
        QuanLy();
        list<MonAn> getDatabase();
        uint8_t getSoBan();

};


QuanLy::QuanLy(){
    QuanLy ql;
    int option;

    do
    {
        cout << "---------------------------" << endl;
        cout << "1. Them mon." << endl;
        cout << "2. Sua mon." << endl;
        cout << "3. Xoa mon." << endl;
        cout << "4. Danh sach mon." << endl;
        cout << "5. Thiet lap so ban." << endl;;
        cout << "0. Quay lai." << endl;
        cout << "---------------------------" << endl;
        cout << "Nhap vao:... ";
        cin >> option;
    } while (option!=0);
    
    switch (option)
    {
    case 1:
        ql.themMon();
        break;
    case 2:
        ql.suaMon();
        break;
    case 3:
        ql.xoaMon();
        break;
    case 4:
        ql.danhSachMon();
        break;
    case 5:
        ql.thietLapSoBan();
        break;
    case 0:
        
        break;
    
    default:
        cout<<"vui long nhap dung !!!";
        break;
    }

}

list<MonAn> QuanLy::getDatabase(){
    return this->DATABASE;
}


uint8_t QuanLy::getSoBan(){
    return this->SO_BAN;
}


void QuanLy::themMon() {
    string ten;
    double gia;

    cout << "Nhap ten mon an: ";
    cin >> ten;
    cout << "Nhap gia mon an: ";
    cin >> gia;

    MonAn mon(ten, gia);
    DATABASE.push_back(mon);
}

void QuanLy::suaMon() {
    uint8_t id;
    cout << "Nhap ID mon an can sua: ";
    cin >> id;

    for (auto& mon : DATABASE) {
        if (mon.getID() == id) {
            cout << "Nhap ten moi: ";
            string ten;
            cin >> ten;
            mon.setTen();
            cout << "Nhap gia moi: ";
            double gia;
            cin >> gia;
            mon.setGia();
            cout << "Mon an da duoc sua." << endl;
            return;
        }
    }

    cout << "Khong tim thay mon an voi ID " << id << endl;
}

void QuanLy::xoaMon() {
    uint8_t id;
    cout << "Nhap ID mon an can xoa: ";
    cin >> id;

    for (auto it = DATABASE.begin(); it != DATABASE.end(); ++it) {
        if (it->getID() == id) {
            DATABASE.erase(it);
            cout << "Mon an da duoc xoa." << endl;
            return;
        }
    }

    cout << "Khong tim thay mon an voi ID " << id << endl;
}

void QuanLy::danhSachMon() {
    cout << "Danh sach mon an:" << endl;
    for (const auto& mon : DATABASE) {
        cout << "ID: " << mon.getID() << ", Ten: " << mon.getTen() << ", Gia: " << mon.getGia() << endl;
    }
}

void QuanLy::thietLapSoBan() {
    cout << "Nhap so ban: ";
    cin >> SO_BAN;
}


class ThongTinBan{
    private:
        uint8_t SO_BAN;
        bool TRANG_THAI;
        typedef struct{
            MonAn MON_AN;
            uint8_t SO_LUONG;
        }TypeMon;
        list<TypeMon> DATABASE_MON_AN;
    public:
        ThongTinBan(uint8_t soBan, bool trangThai);
        uint8_t getSoBan();
        bool setTrangThai();
        bool getTrangThai();
        void danhSachMon();
        void themMon(MonAn mon, uint8_t soLuong);
        void suaMon(uint8_t id, uint8_t soLuong);
        void xoaMon(uint8_t id);
};

void ThongTinBan::xoaMon(uint8_t id){

    auto position = DATABASE_MON_AN.begin();
    for(auto item : DATABASE_MON_AN){
        if(item.MON_AN.getID() == id){
            DATABASE_MON_AN.erase(position);
            position++;
        }
    }
}

class NhanVien{
    private:
        list<MonAn> DATABASE_MON_AN;
        list<ThongTinBan> DATABASE_BAN;
    public:
        NhanVien(list<MonAn> database, uint8_t soBan);
};

NhanVien::NhanVien(list<MonAn> database, uint8_t soBan){
    DATABASE_MON_AN.assign(database.begin(), database.end());

    for (uint8_t i = 1; i < soBan; i++)
    {
        ThongTinBan ban (i, false);
        DATABASE_BAN.push_back(ban);
    }
    
}

typedef enum{
    QUAN_LY,
    NHAN_VIEN
}Menu;

int main(int argc, char const *argv[])
{
    PROMPT_OPTION;

    switch ((Menu)x)
    {
    case QUAN_LY:
        
        break;
    case NHAN_VIEN:
        
        break;
    
    default:
        break;
    }
    
    return 0;
}
