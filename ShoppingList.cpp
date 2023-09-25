//
// Created by andrea on 12/09/2023.
//

#include <iostream>
#include "ShoppingList.h"

//l'aggiunta di un oggetto comporta il riordino della lista in base alle categorie
void ShoppingList::addItem(std::unique_ptr<Item> i) {
    auto it = list.find(i->getCategory());

    if (it != list.end()) {
        // significa che è già stato inserito un elemento di questa categoria, allora basta aggiungere l'item alla mappa degli item
        auto ptr = it->second.find(i->getName());

        // se è già presente un item con quel nome si sostituisce con quello nuovo
        if (ptr != it->second.end())
            it->second.erase(ptr);
        it->second.insert(std::make_pair(i->getName(), std::move(i)));
    } else {
        // ancora non c'è un elemento di questa categoria, bisogna crearne una nuova
        std::map<std::string, std::unique_ptr<Item>> m;
        auto itemCategory = i->getCategory();
        m.insert(std::make_pair(i->getName(), std::move(i)));
        list.insert(std::make_pair(itemCategory, std::move(m)));
    }
    notify();
}

void ShoppingList::removeItem(const std::string &i, std::string category) {

    auto it = list.find(category);
    if (it != list.end()) {
        auto ptr = it->second.find(i);
        if (ptr != it->second.end()) {
            it->second.erase(i);
            notify();
        } else
            std::cout << i << " is not in " << this->name << " list." << std::endl;
    } else
        std::cout << i << " is not in " << this->name << " list." << std::endl;
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

    std::string result;
    for (char c : name) {
        result += std::toupper(c); // Converte il carattere in maiuscolo e lo aggiunge a result
    }
    std::cout <<"------------------------------\n"<< result << ":\n" << std::endl;

    for (auto &it: list) {
        std::cout<<it.first<<":"<<std::endl;
        for (auto &ptr: it.second)
            ptr.second->getInfo();
    }

    std::cout<<"---------------------------------\n"<<std::endl;
}

void ShoppingList::buyItem(const std::string &i, std::string category) {

        auto it = list.find(category);
        if (it != list.end()) {
            auto ptr = it->second.find(i);
            if (ptr != it->second.end()) {
                ptr->second->setToBuy(false);
                notify();
            } else
                std::cout << i << " is not in " << this->name << " list." << std::endl;
        } else
            std::cout << i << " is not in " << this->name << " list." << std::endl;

}

bool ShoppingList::checkItem(std::string category, std::string name) {
    auto it = list.find(category);
    if (it != list.end()) {
        auto ptr = it->second.find(name);
        if (ptr != it->second.end())
            return true;
        else
            return false;
    } else
        return false;
}

bool ShoppingList::checkUser(std::shared_ptr<AbstractUser> user) {
    for (auto &it: users) {
        if (it->getId() == user->getId())
            return true;
    }
    return false;
}
