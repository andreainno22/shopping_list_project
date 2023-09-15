#include <iostream>
#include "User.h"
#include "FoodItem.h"
#include "NotFoodItem.h"

int main() {

    std::shared_ptr<ShoppingListCatalogue> catalogue(new ShoppingListCatalogue());
    std::shared_ptr<User> andrea (new User("andrea", "innocenti", catalogue));

    andrea->createShoppingList("prima_lista");
    andrea->addItem("prima_lista", std::make_unique<FoodItem>(FoodCategory::vegetables, "carrots"));
    andrea->addItem("prima_lista", std::make_unique<NotFoodItem>(Category::kitchen,"scottex"));
    std::shared_ptr<User> pippo(new User("pippo", "pippi", catalogue));
    pippo->showCatalogue();
    pippo->addShoppingList("prima_lista");
    pippo->addItem("prima_lista", std::make_unique<FoodItem>(FoodCategory::meat, "chicken", 1, false, true, 1));
    andrea->printList("prima_lista");
    pippo->printList("prima_lista");
}
