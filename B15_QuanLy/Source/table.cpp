/*
* File: table.cpp
* Author: DO NGOC KHANG
* Date: 07/07/2023
* Description: 
*/
#include "table.hpp"
#include "dish.hpp"

Table::Table(){}

Table::Table(uint8_t id, bool status){
    this->id = id;
    this->status = status;
}

/*
* Class: Table
* Function: setID
* Description: This function use for set ID of table
* Input:
*   id - ID of table
* Output:
*   return: None
*/
void Table::setID(uint8_t id){
    this->id = id;
}

/*
* Class: Table
* Function: get_ID
* Description: This function use for get ID of table
* Input:
*   Don't have input parameters
* Output:
*   return ID of a Table
*/
uint8_t Table::getID(){
    return id;
}

/*
* Class: Table
* Function: set_Status
* Description: This function use for set status of table
* Input:
*   status - Status of table
* Output:
*   return: None
*/
void Table::set_Status(bool status){
    this->status = status;
}

/*
* Class: Table
* Function: get_Status
* Description: This function use for get status of table
* Input:
*   Don't have input parameters
* Output:
*   return status of a table
*/
uint8_t Table::get_Status(){
    return status;
}

/*
* Class: Table
* Function: set_ListDish
* Description: This function use for set list dish of table
* Input:
*   dish - Dish of table
* Output:
*   return: None
*/
void Table::set_ListDish(Dish dish){
    uint8_t command;
    if(command == 0){
        list_Dish.clear();
    }else if(command == 1){
        list_Dish.push_back(dish);
    }
}

/*
* Class: Tables
* Function: set_ID
* Description: This function use for get list dish of table
* Input:
*   Don't have input parameters
* Output:
*   return list dish of a table
*/
list<Dish> Table::get_ListDish(){
    return list_Dish;
}

