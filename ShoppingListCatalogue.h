//
// Created by andrea on 13/09/2023.
//

#ifndef SHOPPING_LIST_PROJECT_SHOPPINGLISTCATALOGUE_H
#define SHOPPING_LIST_PROJECT_SHOPPINGLISTCATALOGUE_H

#include <map>
#include "ShoppingList.h"

class ShoppingListCatalogue {
public:
    ShoppingListCatalogue()= default;

    virtual ~ShoppingListCatalogue();

    void addShoppingList(std::shared_ptr<ShoppingList> s);

    void printAll() const;

    std::shared_ptr<ShoppingList> findList(const std::string& listName) const;

private:
    std::map<std::string , std::shared_ptr<ShoppingList>> catalogue;

};


#endif //SHOPPING_LIST_PROJECT_SHOPPINGLISTCATALOGUE_H
