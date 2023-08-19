/*
* File: manager.hpp
* Author: DO NGOC KHANG
* Date: 07/07/2023
* Description: 
*/

#ifndef __MANAGER_H
#define __MANAGER_H
#include <iostream>
#include <string>
#include <list>
#include "dish.hpp"
#include "Table.hpp"

using namespace std;

#define KEY_INPUT_DISPLAY(func, ...)                \
    void func(){                                    \
        cout<<"Chuong trinh: \n"<<#func<<endl;      \
        int phim;                                   \
        do{                                         \
            _VA_ARGS__                              \
            cin>>phim;                              \
        } while (1);                                \    
    }


class Manager{
    private:
        list<Dish> list_Dish;
        list<Table> list_Table;
        uint8_t tableNumber;
        void set_TableNumber();
        void add_Dish();
        void update_Dish();
        void remove_Dish();
        void set_dishCaculated();
    public:
        Manager();
        list<Dish> get_listDish();
        list<Table> get_listTable();
        uint8_t get_TableNumber();
        uint8_t show_Dishes();
};

#endif