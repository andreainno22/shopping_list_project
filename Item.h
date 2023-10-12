//
// Created by andrea on 11/09/2023.
//

#ifndef SHOPPING_LIST_PROJECT_ITEM_H
#define SHOPPING_LIST_PROJECT_ITEM_H


#include <string>
#include <utility>

class Item { ;
public:
    explicit Item(const std::string &name, int amount = 1) : quantity(amount), toBuy(true), name(name) {}

    const std::string &getName() const {
        return name;
    }

    virtual ~Item() {}

    virtual void getInfo() const = 0;

    virtual const std::string &getCategory() const = 0;

    virtual void setToBuy(bool toBuy) = 0;

    virtual bool getToBuy() const = 0;

protected:
    int quantity;
    std::string name;
    bool toBuy;
};


#endif //SHOPPING_LIST_PROJECT_ITEM_H
