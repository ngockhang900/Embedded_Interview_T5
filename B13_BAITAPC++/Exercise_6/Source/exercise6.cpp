#include "exercise6.hpp"

Fraction::Fraction(int16_t numerator, int16_t denominator){
    numerator = numerator;
    denominator = denominator;
}
Fraction Fraction::cong(Fraction& other){
    int tuMoi = numerator * other.denominator + denominator * other.numerator;
    int mauMoi = denominator * other.denominator;
    return Fraction(tuMoi, mauMoi);
}

// Fraction Fraction::tru(Fraction& other)s
    

// Fraction Fraction::nhan(Fraction& other)
   

// Fraction Fraction::chia(Fraction& other)

void Fraction::inPhanSo(){
    cout<<numerator<<"/"<<denominator<<endl;
}

