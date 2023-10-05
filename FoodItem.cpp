//
// Created by andrea on 12/09/2023.
//

#include <iostream>
#include "FoodItem.h"

// prints all the infos about the item

void FoodItem::getInfo() const{
    std::cout << name << ", " << kilos << " kilos, quantity: " << quantity << ", to buy: " << std::boolalpha << getToBuy();
    if(forFridge)
        std::cout << ", for fridge";
    if(frozen)
        std::cout << ", frozen";
    std::cout <<"\n"<< std::endl;


}

const std::string FoodItem::getCategory() const {
    return category;
}
