//
// Created by andrea on 12/09/2023.
//

#include <iostream>
#include "ShoppingList.h"

//l'aggiunta di un oggetto comporta il riordino della lista in base alle categorie
void ShoppingList::addItem(std::unique_ptr<Item> i) {
    std::map<std::string, std::unique_ptr<Item>>::iterator it;
    it = list.find(i->getName());
    if (it != list.end())
        list.erase(i->getName());
    list.insert(std::make_pair(i->getName(), std::move(i)));
    notify();
}

void ShoppingList::removeItem(const std::string& i) {

    std::map<std::string, std::unique_ptr<Item>>::iterator it;

    it = list.find(i);
    if (it != list.end())
        notify();
    else
        std::cout << i << " is not in "  << this->name << " list." << std::endl;
}

void ShoppingList::registerUser(std::shared_ptr<AbstractUser> user) {
    this->users.push_back(std::move(user));
}

std::string ShoppingList::getName() const {
    return name;
}

void ShoppingList::setName(const std::string &name) {
    ShoppingList::name = name;
}


ShoppingList::~ShoppingList() {

}

void ShoppingList::notify() {

    for (auto itr = std::begin(users); itr != std::end(users); itr++) {
        (*itr)->update(this->name, this->creatorId);
    }
}

void ShoppingList::removeUser(std::shared_ptr<AbstractUser> user) {

    this->users.remove(user);

}

void ShoppingList::print() {
    std::cout<<name<<'\n'<<std::endl;

    for (auto & it : list) {
        it.second->getInfo();
    }
}
