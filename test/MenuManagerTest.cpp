//
// Created by andrea on 28/09/2023.
//

#include <gtest/gtest.h>
#include "../ShoppingListCatalogue.h"
#include "../MenuManager.h"

TEST(MenuManager, startTest){
    std::shared_ptr<ShoppingListCatalogue> catalogue(new ShoppingListCatalogue());
    MenuManager session = MenuManager(catalogue);
    session.start();
    ASSERT_TRUE(session.isSessionOpen());
}

TEST(MenuManager, showMenuTest){
    std::shared_ptr<ShoppingListCatalogue> catalogue(new ShoppingListCatalogue());
    MenuManager session = MenuManager(catalogue);
    std::shared_ptr<User> user = std::make_shared<User>("Andrea", "Bianchi", catalogue);
    session.showMenu(user);
    ASSERT_TRUE(session.isLogged());
}


