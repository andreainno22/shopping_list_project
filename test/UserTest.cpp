//
// Created by andrea on 22/09/2023.
//

#include "gtest/gtest.h"
#include "../User.h"

class UserTest : public ::testing::Test {
protected:
    void TearDown() override {
        std::cout << "Test finished" << std::endl;
    }

    void SetUp() override {
        this->c = std::make_shared<ShoppingListCatalogue>();
        this->u = std::make_shared<User>(c, 0);
    }

    std::shared_ptr<User> u;
    std::shared_ptr<ShoppingListCatalogue> c;
};

TEST_F(UserTest, addShoppingListTest) {
    u->createShoppingList("test");
    ASSERT_TRUE(u->checkList("test"));
}

TEST_F(UserTest, deleteShoppingListTest) {
    u->createShoppingList("test");
    u->deleteShoppingList("test");
    ASSERT_FALSE(u->checkList("test"));
}

TEST_F(UserTest, addItemTest) {
    u->createShoppingList("test");
    std::unique_ptr<Item> i(new FoodItem("testCat", "testItem"));
    u->addItem("test", std::move(i));
    ASSERT_TRUE(u->checkItem("testCat", "testItem", "test"));
}

TEST_F(UserTest, removeItemTest) {
    u->createShoppingList("test");
    std::unique_ptr<Item> i(new FoodItem("testCat", "testItem"));
    u->addItem("test", std::move(i));
    u->removeItem("testCat", "testItem", "test");
    ASSERT_FALSE(u->checkItem("testCat", "testItem", "test"));
}

TEST_F(UserTest, addListTest){
    u->createShoppingList("test");
    auto u2 = std::make_shared<User>(c, 1);
    u2->addShoppingList("test");
    ASSERT_TRUE(u2->checkList("test"));
}

TEST_F(UserTest, deleteList){
    u->createShoppingList("test");
    u->deleteShoppingList("test");
    ASSERT_FALSE(u->checkList("test"));
}