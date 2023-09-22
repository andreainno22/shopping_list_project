//
// Created by andrea on 11/09/2023.
//

#ifndef SHOPPING_LIST_PROJECT_ITEM_H
#define SHOPPING_LIST_PROJECT_ITEM_H


#include <string>
#include <utility>

class Item { ;
public:
    explicit Item(std::string name, int amount = 1) : amount(amount) , toBuy(true), name(std::move(name)){}

    std::string getName() const {
        return name;
    }

    virtual void getInfo() = 0;

    virtual std::string getCategory() const = 0;

    virtual void setToBuy(bool toBuy) = 0;

    virtual bool getToBuy() const = 0;

protected:
    int amount;
    std::string name;
    bool toBuy;
};


#endif //SHOPPING_LIST_PROJECT_ITEM_H
