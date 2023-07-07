#ifndef __EXERCISE5_H_
#define __EXERCISE5_H_

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class People{
    private:
        string name;
        uint16_t year;
        string address;
    public:
        People(string name, uint16_t year, string address)
        :name(name), year(year), address(address){}
        void InThongtin();
        int TinhTuoi();
};

#endif