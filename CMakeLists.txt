cmake_minimum_required(VERSION 3.16)
project(shopping_list_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(shopping_list_project main.cpp
        Item.cpp
        Item.h
        FoodItem.cpp
        FoodItem.h
        NotFoodItem.cpp
        NotFoodItem.h
        AbstractUser.cpp
        AbstractUser.h
        User.cpp
        User.h
        ShoppingList.cpp
        ShoppingList.h
        AbstractShoppingList.cpp
        AbstractShoppingList.h
        ShoppingListCatalogue.cpp
        ShoppingListCatalogue.h)
