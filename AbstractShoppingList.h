//
// Created by andrea on 13/09/2023.
//

#ifndef SHOPPING_LIST_PROJECT_ABSTRACTSHOPPINGLIST_H
#define SHOPPING_LIST_PROJECT_ABSTRACTSHOPPINGLIST_H


#include <memory>
#include <list>
#include "AbstractUser.h"

class AbstractUser;

// subject
class AbstractShoppingList {
public:
    virtual ~AbstractShoppingList() = default;

    virtual void registerUser(std::shared_ptr<AbstractUser> user) = 0;

    virtual void removeUser(std::shared_ptr<AbstractUser> user) = 0;

    virtual void buyItem(const std::string &i, const std::string &category) = 0;

    virtual void notify() = 0;

    virtual const std::string &getName() const = 0;

    virtual void print() const = 0;

    virtual void removeItem(const std::string &i, const std::string &category) = 0;

    virtual bool checkItem(const std::string &category, const std::string &name) const = 0;

};


#endif //SHOPPING_LIST_PROJECT_ABSTRACTSHOPPINGLIST_H
