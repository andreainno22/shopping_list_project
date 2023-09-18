//
// Created by andrea on 12/09/2023.
//

#include <iostream>
#include "User.h"

int User::globalId = 0;

void User::createShoppingList(std::string listName) {
    std::shared_ptr<ShoppingList> s(new ShoppingList(listName, this->id));
    this->catalogue->addShoppingList(s);
    std::shared_ptr<AbstractShoppingList> s1 = std::move(std::dynamic_pointer_cast<AbstractShoppingList>(s));
    lists.insert(std::make_pair(listName, s1));
    attach(s1);
}

void User::deleteShoppingList(std::string name) {

    auto it = lists.find(name);
    if (it != lists.end()) {
        detach(it->second);
        lists.erase(it);
    } else {
        std::cout << "No lists called " + name << std::endl;
    }
}

void User::addItem(const std::string &shoppingList, std::unique_ptr<Item> item) {
    std::map<std::string, std::shared_ptr<AbstractShoppingList>>::iterator it;
    it = lists.find(shoppingList);
    if (it != lists.end()) {
        std::shared_ptr<ShoppingList> s = std::dynamic_pointer_cast<ShoppingList>(it->second);
        s->addItem(std::move(item));
    } else
        std::cout << "the list " + shoppingList + " doesn't exists" << std::endl;

}

void User::update(std::string listName, int creatorId) {
    auto it = lists.find(listName);
    if (it != lists.end())
        std::cout << this->name << " something changes in " << listName << ", check it!\n" << std::endl;
}

User::~User() {}

//serve per abbonarsi a una nuova lista
void User::attach(std::shared_ptr<AbstractShoppingList> newList) {

    newList->registerUser(shared_from_this());

}

void User::detach(std::shared_ptr<AbstractShoppingList> listName) {
    listName->removeUser(shared_from_this());
}

void User::printList(std::string list) {

    auto it = lists.find(list);
    if (it != lists.end())
        it->second->print();
    else
        std::cout << name << ", no list named " + list + " in your collection\n" << std::endl;
}

void User::showCatalogue() {
    catalogue->printAll();

}

void User::addShoppingList(std::string name) {

    std::shared_ptr<ShoppingList> newList = catalogue->findList(name);
    if (newList == nullptr)
        std::cout << name << " does not exist" << std::endl;
    else {
        std::shared_ptr<AbstractShoppingList> list = std::dynamic_pointer_cast<AbstractShoppingList>(newList);
        this->lists.insert(std::make_pair(name, list));
        attach(list);
    }
}

void User::removeItem(const std::string category, const std::string name, const std::string list) {

    auto it = lists.find(list);
    if (it != lists.end())
        it->second->removeItem(name, category);

}
