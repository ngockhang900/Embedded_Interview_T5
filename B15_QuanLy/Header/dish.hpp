/*
* File: dish.hpp
* Author: DO NGOC KHANG
* Date: 07/07/2023
* Description: 
*/

#ifndef __DISH_H
#define __DISH_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Dish{
    private:
        uint8_t id;
        string name;
        double price;
    public:
        Dish();
        Dish(string name, double price);
        uint8_t getID();
        void setName(string name);
        string getName();
        void setPrice(double price);
        double getPrice();
};

#endif