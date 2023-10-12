#include <utility>

//
// Created by andrea on 26/09/2023.
//

#ifndef SHOPPING_LIST_PROJECT_MENUMANAGER_H
#define SHOPPING_LIST_PROJECT_MENUMANAGER_H

#include <memory>
#include <iostream>
#include "ShoppingListCatalogue.h"
#include "User.h"

class MenuManager {
public:
    explicit MenuManager(std::shared_ptr<ShoppingListCatalogue> &catalogue) : catalogue(std::move(catalogue)),
                                                                              logged(false), sessionOpen(true) {};

    void start();

    void showMenu(const std::shared_ptr<User> &user);

    [[nodiscard]] bool isLogged() const {
        return logged;
    }

    [[nodiscard]] bool isSessionOpen() const {
        return sessionOpen;
    }

private:
    std::shared_ptr<ShoppingListCatalogue> catalogue;
    bool logged;
    bool sessionOpen;

};


#endif //SHOPPING_LIST_PROJECT_MENUMANAGER_H
