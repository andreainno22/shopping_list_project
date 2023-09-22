//
// Created by andrea on 12/09/2023.
//

#include <iostream>
#include "FoodItem.h"


void FoodItem::getInfo() {
    std::cout << name << ", " << kilos << " kilos, amount: " << amount << ", to buy: " << std::boolalpha << getToBuy()
              << "\n"
              << std::endl;
}

std::string FoodItem::getCategory() const {
    return category;
}
