//
// Created by andrea on 12/09/2023.
//

#ifndef SHOPPING_LIST_PROJECT_FOODITEM_H
#define SHOPPING_LIST_PROJECT_FOODITEM_H


#include <string>
#include <utility>
#include "Item.h"

class FoodItem : public Item {
public:
    FoodItem(const std::string& category, const std::string& name, int amount = 1, bool frozen = false, bool forFridge = false,
             float kilos = 0)
            :
            Item(name, amount), category(category), forFridge(forFridge), frozen(frozen),
            kilos(kilos) {};

    void getInfo() const override;

    const std::string getCategory() const override;

    bool getToBuy() const override {
        return toBuy;
    }

    void setToBuy(bool toBuy) override {
        this->toBuy = toBuy;
    }

private:
    bool frozen;
    bool forFridge;
    std::string category;
    float kilos;
};


#endif //SHOPPING_LIST_PROJECT_FOODITEM_H
