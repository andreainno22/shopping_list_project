//
// Created by andrea on 12/09/2023.
//

#ifndef SHOPPING_LIST_PROJECT_SHOPPINGLIST_H
#define SHOPPING_LIST_PROJECT_SHOPPINGLIST_H

#include <string>
#include <utility>
#include <memory>
#include <list>
#include <map>
#include "Item.h"
#include "AbstractShoppingList.h"
#include "AbstractUser.h"
#include "FoodItem.h"

// concrete subject
class ShoppingList : public AbstractShoppingList {
public:
    ShoppingList(std::string name, int creatorId) : name(std::move(name)), creatorId(creatorId) {}

    virtual ~ShoppingList();

    void addItem(std::unique_ptr<Item> i);

    void removeItem(const std::string &i, std::string category) override;

    void buyItem(const std::string &i, std::string category) override;

    void registerUser(std::shared_ptr<AbstractUser> user) override;

    void removeUser(std::shared_ptr<AbstractUser> user) override;

    std::string getName() const override;

    void setName(const std::string &name);

    void notify() override;

    void print() override;

private:
    std::string name;
    int creatorId;
    std::list<std::shared_ptr<AbstractUser>> users;
    std::map<std::string, std::map<std::string, std::unique_ptr<Item>>> list;
};


#endif //SHOPPING_LIST_PROJECT_SHOPPINGLIST_H
