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
    ShoppingList(const std::string &name, int creatorId) : name(name), creatorId(creatorId) {}

    virtual ~ShoppingList();

    void addItem(std::shared_ptr<Item> i);

    void removeItem(const std::string &i, const std::string & category) override;

    void buyItem(const std::string &i, const std::string &category) override;

    void registerUser(std::shared_ptr<AbstractUser> user) override;

    void removeUser(std::shared_ptr<AbstractUser> user) override;

    const std::string getName() const override;

    void print()const override;

    bool checkItem(const std::string& category, const std::string &name) const override;

    bool checkUser(std::shared_ptr<AbstractUser> user);

    void reorderItem(std::list<std::string>& categories) override;

    std::map<std::string, std::map<std::string, std::shared_ptr<Item>>> getList() const;

private:
    void notify() override;

private:
    std::string name;
    int creatorId;
    std::list<std::shared_ptr<AbstractUser>> users;
    std::map<std::string, std::map<std::string, std::shared_ptr<Item>>> list;
};


#endif //SHOPPING_LIST_PROJECT_SHOPPINGLIST_H
