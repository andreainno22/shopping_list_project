#include <iostream>
#include "User.h"
#include "FoodItem.h"
#include "NotFoodItem.h"

int main() {

    std::shared_ptr<ShoppingListCatalogue> catalogue(new ShoppingListCatalogue());
    std::shared_ptr<User> andrea (new User("andrea", "innocenti", catalogue));

    andrea->createShoppingList("prima_lista");
    andrea->addItem("prima_lista", std::make_unique<FoodItem>("vegetables", "carrots"));
    andrea->addItem("prima_lista", std::make_unique<NotFoodItem>("kitchen","scottex"));
    std::shared_ptr<User> pippo(new User("pippo", "pippi", catalogue));
    pippo->showCatalogue();
    pippo->addShoppingList("prima_lista");
    pippo->addItem("prima_lista", std::make_unique<FoodItem>("meat", "chicken", 1, false, true, 1));
    pippo->addItem("prima_lista", std::make_unique<FoodItem>("vegetables", "cetrioli", 1, false, true, 1));
    pippo->printList("prima_lista");
    pippo->removeItem("vegetables", "carrots", "prima_lista");
    andrea->printList("prima_lista");
    pippo->createShoppingList("listaccia");
    andrea->addShoppingList("listaccia");
    andrea->addItem("listaccia", std::make_unique<NotFoodItem>("technology", "phone"));
    andrea->printList("listaccia");
    pippo->deleteShoppingList("listaccia");
    pippo->printList("listaccia");
    andrea->printList("listaccia");

}
