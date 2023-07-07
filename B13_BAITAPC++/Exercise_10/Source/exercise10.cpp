#include "exercise10.hpp"

void Sach::InThongTin(){
    std::cout<<"Ten sach: "<<tenSach<<std::endl;
    std::cout<<"Tac gia: "<<tacGia<<std::endl;
    std::cout<<"Nam xuat ban: "<<XuatBan<<std::endl;
    std::cout<<"So luong: "<<SoLuong<<std::endl;
}


void Sach::MuonSach(){
    if(SoLuong>0){
        SoLuong--;
        std::cout<<"Muon sach thanh cong"<<std::endl;
    }else{
        std::cout<<"Khong muon duoc sach"<<std::endl;
    }
}

void Sach::TraSach(){
    SoLuong++;
    std::cout<<"Tra sach thanh cong"<<std::endl;
}



