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
    FoodItem(std::string category, std::string name, int amount = 1, bool Frozen = false, bool ForFridge = false, float kilos = 0)
            :
            Item(std::move(name), amount), category(std::move(category)), ForFridge(ForFridge), Frozen(Frozen), kilos(kilos) {};

    bool getFrozen() const {
        return Frozen;
    }

    void setFrozen(bool frozen) {
        FoodItem::Frozen = frozen;
    }

    bool getForFridge() const {
        return ForFridge;
    }

    void setForFridge(bool forFridge) {
        FoodItem::ForFridge = forFridge;
    }

    void getInfo() override;

    std::string getCategory() const override;

private:
    bool Frozen;
    bool ForFridge;
    std::string category;
    float kilos;
};


#endif //SHOPPING_LIST_PROJECT_FOODITEM_H
