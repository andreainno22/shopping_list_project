//
// Created by andrea on 25/09/2023.
//

#include "gtest/gtest.h"
#include "../ShoppingList.h"
#include "../User.h"

class ShoppingListTest : public ::testing::Test {
protected:
    void SetUp() override {
        this->user = std::make_shared<User>(std::make_shared<ShoppingListCatalogue>(), 0);
        this->list = std::make_shared<ShoppingList>("test", user->getId());
    }

    std::shared_ptr<ShoppingList> list;
    std::shared_ptr<User> user;
};

TEST_F(ShoppingListTest, registerUserTest) {
    list->registerUser(user);
    ASSERT_TRUE(list->checkUser(user));
}

TEST_F(ShoppingListTest, removeUserTest) {
    list->registerUser(user);
    list->removeUser(user);
    ASSERT_FALSE(list->checkUser(user));
}

TEST_F(ShoppingListTest, addItemTest) {
    std::unique_ptr<Item> i(new FoodItem("testCat", "testItem"));
    list->addItem(std::move(i));
    ASSERT_TRUE(list->checkItem("testCat", "testItem"));
}

TEST_F(ShoppingListTest, removeItemTest) {
    std::unique_ptr<Item> i(new FoodItem("testCat", "testItem"));
    list->addItem(std::move(i));
    list->removeItem("testItem", "testCat");
    ASSERT_FALSE(list->checkItem("testCat", "testItem"));
}


