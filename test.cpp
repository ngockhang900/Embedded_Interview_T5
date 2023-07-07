#include <iostream>

struct PhanSo {
    int tuSo;
    int mauSo;

    // Phương thức khởi tạo
    PhanSo(int tu = 0, int mau = 1) {
        tuSo = tu;
        mauSo = mau;
    }

    // Phương thức cộng 2 phân số
    PhanSo operator+(const PhanSo& other) const {
        int tuMoi = tuSo * other.mauSo + other.tuSo * mauSo;
        int mauMoi = mauSo * other.mauSo;
        return PhanSo(tuMoi, mauMoi);
    }

    // Phương thức trừ 2 phân số
    PhanSo operator-(const PhanSo& other) const {
        int tuMoi = tuSo * other.mauSo - other.tuSo * mauSo;
        int mauMoi = mauSo * other.mauSo;
        return PhanSo(tuMoi, mauMoi);
    }

    // Phương thức nhân 2 phân số
    PhanSo operator*(const PhanSo& other) const {
        int tuMoi = tuSo * other.tuSo;
        int mauMoi = mauSo * other.mauSo;
        return PhanSo(tuMoi, mauMoi);
    }

    // Phương thức chia 2 phân số
    PhanSo chia(const PhanSo& other) const {
        int tuMoi = tuSo * other.mauSo;
        int mauMoi = mauSo * other.tuSo;
        return PhanSo(tuMoi, mauMoi);
    }
};

int main() {
    PhanSo ps1(3, 4);
    PhanSo ps2(2, 5);

    PhanSo tong = ps1 + ps2;
    PhanSo hieu = ps1 - ps2;
    PhanSo tich = ps1 * ps2;
    PhanSo thuong = ps1.chia(ps2);

    std::cout << "Tong: " << tong.tuSo << "/" << tong.mauSo << std::endl;
    std::cout << "Hieu: " << hieu.tuSo << "/" << hieu.mauSo << std::endl;
    std::cout << "Tich: " << tich.tuSo << "/" << tich.mauSo << std::endl;
    std::cout <<thuong.tuSo<<"/"<<thuong.mauSo << std::endl;

    return 0;
}
