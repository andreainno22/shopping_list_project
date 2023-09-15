//
// Created by andrea on 12/09/2023.
//

#ifndef SHOPPING_LIST_PROJECT_FOODITEM_H
#define SHOPPING_LIST_PROJECT_FOODITEM_H


#include <string>
#include <utility>
#include "Item.h"


enum class FoodCategory {
    vegetables, meat, fish, dairy, fruits, carbohydrates, drinks, other
};

class FoodItem : public Item {
public:
    FoodItem(FoodCategory c, std::string name, int amount = 1, bool Frozen = false, bool ForFridge = false, float kilos = 0)
            :
            Item(std::move(name), amount), category(c), ForFridge(ForFridge), Frozen(Frozen), kilos(kilos) {};

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

private:
    bool Frozen;
    bool ForFridge;
    FoodCategory category;
    float kilos;
};


#endif //SHOPPING_LIST_PROJECT_FOODITEM_H
