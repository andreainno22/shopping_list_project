//
// Created by andrea on 12/09/2023.
//

#include <iostream>
#include "ShoppingList.h"

void ShoppingList::addItem(std::shared_ptr<Item> i) {
    auto it = list.find(i->getCategory());

    if (it != list.end()) {
        // significa che è già stato inserito un elemento di questa categoria, allora basta aggiungere l'item alla mappa degli item di quella categoria
        auto ptr = it->second.find(i->getName());

        // se è già presente un item con quel nome si sostituisce con quello nuovo
        if (ptr != it->second.end())
            it->second.erase(ptr);
        it->second.insert(std::make_pair(i->getName(), std::move(i)));
    } else {

        // ancora non c'è un elemento di questa categoria, bisogna crearne una nuova
        std::map<std::string, std::shared_ptr<Item>> m;
        auto itemCategory = i->getCategory();
        m.insert(std::make_pair(i->getName(), std::move(i)));
        list.insert(std::make_pair(itemCategory, std::move(m)));
    }
    notify();
}

void ShoppingList::removeItem(const std::string &i, std::string category) {

    auto it = list.find(category);
    if (it != list.end()) {
        // se esiste la categoria allora cerco l'item
        auto ptr = it->second.find(i);
        // se esiste l'item lo elimino
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

ShoppingList::~ShoppingList() {}

void ShoppingList::notify() {

    // notifica ad ogni user abbonato alla lista che è stata modificata
    for (auto itr = std::begin(users); itr != std::end(users); itr++) {
        (*itr)->update(this->name, this->creatorId);
    }
}

void ShoppingList::removeUser(std::shared_ptr<AbstractUser> user) {

    this->users.remove(user);

}

void ShoppingList::print() {

    std::string result;
    for (char c: name) {
        result += std::toupper(c); // Converte il carattere in maiuscolo e lo aggiunge a result
    }
    std::cout << "------------------------------\n" << result << ":\n" << std::endl;

    for (auto rit = list.rbegin(); rit != list.rend(); ++rit) {
        std::cout << rit->first << ":" << std::endl;
        for (auto &ptr: rit->second)
            ptr.second->getInfo();
    }

    std::cout << "---------------------------------\n" << std::endl;
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

void ShoppingList::reorderItem(std::list<std::string> categories) {

    // riordina la mappa secondo l'ordine specificato nella lista categories

    std::map<std::string, std::map<std::string, std::shared_ptr<Item>>> newList;
    for (auto &it: categories) {
        auto ptr = list.find(it);
        if (ptr != list.end()) {
            newList.insert(std::make_pair(it, std::move(ptr->second)));
        }
    }
    list = std::move(newList);
    notify();

}

std::map<std::string, std::map<std::string, std::shared_ptr<Item>>> ShoppingList::getList() const {
    return list;
}
