#include "User.h"
#include "NotFoodItem.h"
#include "MenuManager.h"

int main() {

    // start of the program

    std::shared_ptr<ShoppingListCatalogue> catalogue(new ShoppingListCatalogue());
    MenuManager session = MenuManager(catalogue);
    session.start();

}
