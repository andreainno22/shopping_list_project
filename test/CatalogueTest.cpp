//
// Created by andrea on 25/09/2023.
//

#include "gtest/gtest.h"
#include "../ShoppingListCatalogue.h"

TEST(CatalogueTest, addListTest) {
    ShoppingListCatalogue c;
    auto list = std::make_shared<ShoppingList>("test", 0);
    c.addShoppingList(list);
    ASSERT_TRUE(c.findList("test"));
}
