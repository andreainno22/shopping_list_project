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
            Item(std::move(name), amount), category(std::move(category)), forFridge(ForFridge), frozen(Frozen), kilos(kilos) {};

    bool getFrozen() const {
        return frozen;
    }

    void setFrozen(bool frozen) {
        FoodItem::frozen = frozen;
    }

    bool getForFridge() const {
        return forFridge;
    }

    void setForFridge(bool forFridge) {
        FoodItem::forFridge = forFridge;
    }

    void getInfo() override;

    std::string getCategory() const override;

    bool getToBuy() const override{
        return toBuy;
    }

    void setToBuy(bool toBuy) override{
        this->toBuy = toBuy;
    }

private:
    bool frozen;
    bool forFridge;
    std::string category;
    float kilos;
};


#endif //SHOPPING_LIST_PROJECT_FOODITEM_H
