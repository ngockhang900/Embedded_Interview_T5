#include <iostream>
#include <string>

using namespace std;

class Fraction{
    private:
        int numerator;
        int denominator;
    public:
        Fraction(int16_t numerator, int16_t denominator);
        Fraction cong(const Fraction& other)const;
        void inphanso()const;
};

Fraction::Fraction(int16_t numerator, int16_t denominator){
    this->numerator = numerator;
    this->denominator = denominator;
}
Fraction Fraction::cong(const Fraction& other)const{
    int tuMoi = numerator * other.denominator + denominator * other.numerator;
    int mauMoi = denominator * other.denominator;
    return Fraction(tuMoi, mauMoi);
}
void Fraction::inphanso()const{
    cout <<numerator<<"/"<<denominator<<endl;

}

int main()
{
    Fraction ps1(1,2);
    Fraction ps2(3,4);
    Fraction con = ps1.cong(ps2);
    con.inphanso();
    return 0;
}