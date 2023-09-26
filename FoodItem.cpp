//
// Created by andrea on 12/09/2023.
//

#include <iostream>
#include "FoodItem.h"


void FoodItem::getInfo() {
    std::cout << name << ", " << kilos << " kilos, amount: " << amount << ", to buy: " << std::boolalpha << getToBuy();
    if(forFridge)
        std::cout << ", for fridge";
    if(frozen)
        std::cout << ", frozen";
    std::cout <<"\n"<< std::endl;


}

std::string FoodItem::getCategory() const {
    return category;
}
