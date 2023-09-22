//
// Created by andrea on 12/09/2023.
//

#ifndef SHOPPING_LIST_PROJECT_NOTFOODITEM_H
#define SHOPPING_LIST_PROJECT_NOTFOODITEM_H


#include <string>
#include <utility>
#include "Item.h"

class NotFoodItem : public Item {
public:
    NotFoodItem(std::string category, std::string name, int amount = 1) : category(category), Item(std::move(name), amount) {}

    void getInfo() override;

    bool getToBuy() const override{
        return toBuy;
    }

    void setToBuy(bool toBuy) override{
        this->toBuy = toBuy;
    }

    std::string getCategory() const override;

private:
    std::string category;
};


#endif //SHOPPING_LIST_PROJECT_NOTFOODITEM_H
