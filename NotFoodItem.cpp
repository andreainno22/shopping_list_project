//
// Created by andrea on 12/09/2023.
//

#include <iostream>
#include "NotFoodItem.h"

// prints all the infos about the item

void NotFoodItem::getInfo() const{
    std::cout << name << ", quantity: " << quantity << ", to buy: " << std::boolalpha << getToBuy() << "\n" << std::endl;
}

const std::string NotFoodItem::getCategory() const {
    return category;
}
