//
// Created by andrea on 12/09/2023.
//

#ifndef SHOPPING_LIST_PROJECT_NOTFOODITEM_H
#define SHOPPING_LIST_PROJECT_NOTFOODITEM_H


#include <string>
#include <utility>
#include "Item.h"

enum Category {
    technology, kitchen, bathroom, other
};

class NotFoodItem : public Item {
public:
    NotFoodItem(Category c, std::string name, int amount = 1) : category(c), Item(std::move(name), amount) {}

    void getInfo() override ;

private:
    Category category;
};


#endif //SHOPPING_LIST_PROJECT_NOTFOODITEM_H
