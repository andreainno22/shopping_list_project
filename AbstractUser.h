//
// Created by andrea on 12/09/2023.
//

#ifndef SHOPPING_LIST_PROJECT_ABSTRACTUSER_H
#define SHOPPING_LIST_PROJECT_ABSTRACTUSER_H

#include <string>
#include <memory>
#include "AbstractShoppingList.h"

class AbstractShoppingList;
// Observer
class AbstractUser : public std::enable_shared_from_this<AbstractUser> {
public:
    virtual ~AbstractUser() = default;

    virtual void update(const std::string &listName, int creatorId) = 0;

    virtual void attach(std::shared_ptr<AbstractShoppingList> listName) = 0;

    virtual void detach(std::shared_ptr<AbstractShoppingList> listName) = 0;

    virtual int getId() const = 0;

};


#endif //SHOPPING_LIST_PROJECT_ABSTRACTUSER_H
