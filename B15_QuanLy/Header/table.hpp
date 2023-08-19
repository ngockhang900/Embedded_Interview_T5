/*
* File: table.hpp
* Author: DO NGOC KHANG
* Date: 07/07/2023
* Description: 
*/

#ifndef __TABLE_H
#define __TABLE_H
#include<iostream>
#include <string>
#include <list>
#include <dish.hpp>

using namespace std;

class Table{
    private:
        uint8_t id;
        bool status;
        list<Dish> list_Dish;;
    public:
        Table();
        Table(uint8_t id, bool status);
        void setID(uint8_t id);
        uint8_t getID();
        void set_Status(bool status);
        uint8_t get_Status();
        void set_ListDish(Dish dish);
        list<Dish> get_ListDish();
};

#endif