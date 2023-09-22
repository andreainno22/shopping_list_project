//
// Created by andrea on 12/09/2023.
//

#ifndef SHOPPING_LIST_PROJECT_USER_H
#define SHOPPING_LIST_PROJECT_USER_H


#include <string>
#include <map>
#include <utility>
#include "AbstractUser.h"
#include "ShoppingList.h"
#include "ShoppingListCatalogue.h"
#include <memory>

// concrete observer

class User : public AbstractUser {
public:
    User(std::string name, std::string surname, std::shared_ptr<ShoppingListCatalogue> c) : name(std::move(name)),
                                                                                            surname(std::move(surname)),
                                                                                            catalogue(std::move(c)) {
        id = globalId++;
    }

    ~User() override;

    void update(std::string listName, int creatorId) override;

    void createShoppingList(std::string listName);

    void deleteShoppingList(std::string name);

    void addShoppingList(std::string name);

    void addItem(const std::string &shoppingList, std::unique_ptr<Item> item);

    void removeItem(std::string category, std::string name, std::string list);

    void attach(std::shared_ptr<AbstractShoppingList> listName) override;

    void detach(std::shared_ptr<AbstractShoppingList> listName) override;

    void printList(std::string list);

    void showCatalogue();

    void buyItem(std::string category, std::string name, std::string list);

private:
    std::map<std::string, std::shared_ptr<AbstractShoppingList>> lists;
    std::string name, surname;
    int id;
    static int globalId;
    std::shared_ptr<ShoppingListCatalogue> catalogue;
};


#endif //SHOPPING_LIST_PROJECT_USER_H
