//
// Created by andrea on 12/09/2023.
//

#include <iostream>
#include "NotFoodItem.h"

void NotFoodItem::getInfo() {
    std::cout << name << ", amount: " << amount << "\n" << std::endl;
}

std::string NotFoodItem::getCategory() const {
    return category;
}
