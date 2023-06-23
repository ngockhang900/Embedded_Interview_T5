#include <iostream>
#include <string>

using namespace std;

class Fraction{
    private:
        int16_t numerator;
        int16_t denominator;
    public:
        Fraction(int16_t tuSo, int16_t mauSo);
        int16_t cong();
        int16_t tru();
        int16_t nhan();
        int16_t chia();
};

Fraction::Fraction(int16_t tuSo, int16_t mauSo){
    numerator = tuSo;
    denominator = mauSo;
}

int16_t Fraction::cong(){
    return numerator + denominator;
}

int16_t Fraction::tru(){
    return numerator - denominator;
}

int16_t Fraction::nhan(){
    return numerator * denominator;
}

int16_t Fraction::chia(){
    return numerator / denominator;
}

int main(int argc, char const *argv[])
{
    Fraction PS(14,2);
    cout<<"Phep cong: "<<PS.cong()<<endl;
    cout<<"Phep tru: "<<PS.tru()<<endl;
    cout<<"Phep nhan: "<<PS.nhan()<<endl;
    cout<<"Phep chia: "<<PS.chia()<<endl;
    return 0;
}
