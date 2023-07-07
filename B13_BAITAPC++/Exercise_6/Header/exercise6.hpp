#ifndef __EXERCISE6_H
#define __EXERCISE6_H

#include <iostream>
#include <string>

using namespace std;

class Fraction{
    private:
        float numerator;
        float denominator;
    public:
        Fraction(int16_t numerator, int16_t denominator);
        float cong(Fraction& other);
        // Fraction tru(Fraction& other);
        // Fraction nhan(Fraction& other);
        // Fraction chia(Fraction& other);
        void inPhanSo();
};

#endif