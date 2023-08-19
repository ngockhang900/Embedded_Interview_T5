/*
* File: manager.cpp
* Author: DO NGOC KHANG
* Date: 07/07/2023
* Description: 
*/
#include "manager.hpp"

Manager::Manager(){
    int x;

        cout<<"vui long chon: \n";
        cout<<" 1. Add dish\n";
        cout<<" 2. Edit dish\n";
        cout<<" 3. Remove dish\n";
        cout<<" 4. Dish list\n";
        cout<<" 5. Set the number of tables\n";
        cin>>x;
         switch (x)
    {
    case 1:
        add_Dish();
        break;
    case 2:
        cout<<"so 2\n";
        break;
    case 3:
        cout<<"so 3\n";
        break;
    case 4:
        cout<<"so 4\n";
        break;
    case 5:
        set_TableNumber();
        break;
    default:
        cout << "Invalid selection. Please re-enter.\n";
        break;
    }
   
    
}

/*
* Class: Manager
* Function: set_TableNumber
* Description: This function use for set number of tables
* Input:
*   Dont have input parameters
* Output:
*   return: None
*/
void Manager::set_TableNumber(){
    
}

/*
* Class: Manager
* Function: add_Dish
* Description: This function use for set new dish
* Input:
*   Dont have input parameters
* Output:
*   return: None
*/
void Manager::add_Dish(){
    string nameDish;
    double price;
    int z;

        do
        {
            cout<<"1. Keep adding dishes\n";
            cout<<"0. Come back\n";
            cout<<"Please enter: ";
            cin>>z;

            if(z == 1){
                cout<<"Enter dish name: ";
                cin>>nameDish;
                cout<<"Enter the price of the dish: ";
                cin>>price;
                Dish dis(nameDish, price);
                list_Dish.push_back(dis);
            }else if(z == 0){
                Manager ql;
            }
        } while (z != 0);
    
}

// /*
// * Class: Manager
// * Function: update_Dish
// * Description: This function use for update disd which has created
// * Input:
// *   Dont have input parameters
// * Output:
// *   return: None
// */
void Manager::update_Dish(){

}

//  /*
//  * Class: Manager
//  * Function: remove_Dish
//  * Description: This function use for remove dish which has created
//  * Input:
//  *   Don't have input parameter
//  * Output:
//  *   return: None
//  * */
// void Manager::remove_Dish(){

// }

// /*
// * Class: Manager
// * Function: show_Dishes
// * Description: This function usr for show dishes which has created
// * Input:
// *   Don't have input parameter
// * Output:
// *   return status of list dish
// */
// uint8_t Manager::show_Dishes(){

// }

// /*
// * Class: Manager
// * Function: set_Dish_Caculated
// * Description: This function usr for set dish when oder or caculated
// * Input:
// *   Don't have input parameter
// * Output:
// *   return status of list dish
// */
// void Manager::set_dishCaculated(){

// }

// /*
// * Class: Manager
// * Function: get_listDish
// * Description: This function usr for get list of dishes
// * Input:
// *   Don't have input parameter
// * Output:
// *   return list of dishes
// */
// list<Dish> Manager::get_listDish(){

// }

// /*
// * Class: Manager
// * Function: get_listTable
// * Description: This function usr for get list of tables
// * Input:
// *   Don't have input parameter
// * Output:
// *   return list of tables
// */
// list<Table> Manager::get_listTable(){

// }   

// /*
// * Class: Manager
// * Function: get_TableNumber
// * Description: This function usr for get number of table
// * Input:
// *   Don't have input parameter
// * Output:
// *   return number of table
// */
// uint8_t Manager::get_TableNumber(){

// }