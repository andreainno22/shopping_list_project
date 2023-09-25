cmake_minimum_required(VERSION 3.16)
project(shopping_list_project)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(test)
add_executable(shopping_list_project main.cpp)
set(SOURCE_FILES
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
add_library(core ${SOURCE_FILES})
target_link_libraries(shopping_list_project core)


