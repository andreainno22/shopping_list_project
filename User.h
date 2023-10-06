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
    User(const std::string &name, const std::string &surname, std::shared_ptr<ShoppingListCatalogue> c) : name(name),
                                                                                            surname(surname),
                                                                                            catalogue(std::move(c)) {
        id = globalId++;
    }

    User(std::shared_ptr<ShoppingListCatalogue> c, int id){
        this->catalogue = std::move(c);
        this->id = id;
    }

    int getId() const override;

    ~User() override;

    void update(const std::string &listName, int creatorId) override;

    void createShoppingList(const std::string &listName);

    void deleteShoppingList(const std::string &name);

    void addShoppingList(const std::string &name);

    void addItem(const std::string &shoppingList, std::unique_ptr<Item> item);

    void removeItem(const std::string& category, const std::string &name, const std::string &list);

    void printList(const std::string &list) const;

    void showCatalogue() const;

    void buyItem(const std::string& category, const std::string& name, const std::string& list);

    bool checkList(const std::string& list) const;

    bool checkItem(const std::string& category, const std::string& name, const std::string& list) const;

    const std::string &getName() const;

    const std::string &getSurname() const;

    const void printAllLists() const;

private:
    void attach(std::shared_ptr<AbstractShoppingList> listName) override;

    void detach(std::shared_ptr<AbstractShoppingList> listName) override;

private:
    std::map<std::string, std::shared_ptr<AbstractShoppingList>> lists;
    std::string name, surname;
    int id;
    static int globalId;
    std::shared_ptr<ShoppingListCatalogue> catalogue;
};


#endif //SHOPPING_LIST_PROJECT_USER_H
