/*
* File: dish.cpp
* Author: DO NGOC KHANG
* Date: 07/07/2023
* Description: 
*/
#include "dish.hpp"
#include "manager.hpp"


Dish::Dish(){}

Dish::Dish(string name, double price){
    static uint8_t ID = 1;
    this->id = ID;
    ID++;

    this->name = name;
    this->price = price;
}

/*
* Class: Dish
* Function: getID
* Description: This function use for get the result of ID
* Input:
*   Don't have input parameters
* Output:
*   return the ID of a dish
*/
uint8_t Dish::getID(){
    return this->id;
}

/*
* Class: Dish
* Function: setName
* Description:  This function use for set name of a dish
* Input:
*   name - Name of dish
* Output:
*   return: None
*/
void Dish::setName(string name){
    this->name = name;
}

/*
* Class: Dish
* Function: getName
* Description: This function use for get name of a dish
* Input:
*   Don't have input parameters
* Output:
*   return the name of a dish
*/
string Dish::getName(){
    return name;
}

/*
* Class: Dish
* Function: setPrice
* Description:  This function use for set price of a dish
* Input:
*   price - Price of dish
* Output:
*   return: None
*/
void Dish::setPrice(double price){
    this->price = price;
}

/*
* Class: Dish
* Function: getPrice
* Description: This function use for get price of a dish
* Input:
*   Don't have input parameters
* Output:
*   return the price of a dish
*/
double Dish::getPrice(){
    return price;
}



