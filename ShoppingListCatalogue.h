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

    void addShoppingList(const std::shared_ptr<ShoppingList>& s);

    void removeShoppingList(std::string s);

    void printAll();

    std::shared_ptr<ShoppingList> findList(const std::string& listName);

private:
    std::map<std::string , std::shared_ptr<ShoppingList>> catalogue;

};


#endif //SHOPPING_LIST_PROJECT_SHOPPINGLISTCATALOGUE_H
