//
// Created by andrea on 13/09/2023.
//

#include "ShoppingListCatalogue.h"

ShoppingListCatalogue::~ShoppingListCatalogue() {}

void ShoppingListCatalogue::addShoppingList(std::shared_ptr<ShoppingList> s) {
    this->catalogue.insert(std::make_pair(s->getName(), s));
}

void ShoppingListCatalogue::printAll() const {

    for (auto &it: catalogue)
        it.second->print();
}

std::shared_ptr<ShoppingList> ShoppingListCatalogue::findList(const std::string &listName) const {

    auto it = catalogue.find(listName);

    if (it != catalogue.end())
        return it->second;
    else
        return nullptr;
}

