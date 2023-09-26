//
// Created by andrea on 26/09/2023.
//

#include "MenuManager.h"
#include "NotFoodItem.h"

void MenuManager::start() {
    int choice;
    std::cout << "Welcome to the Shopping List Manager!" << std::endl;
    std::cout << "What do you want to do?" << std::endl;
    std::cout << "1. Login" << std::endl;
    std::cout << "2. Exit" << std::endl;
    std::cin >> choice;
    switch (choice) {
        case 1: {
            std::string name, surname;
            std::cout << "Insert your name: ";
            std::cin >> name;
            std::cout << "Insert your surname: ";
            std::cin >> surname;
            std::shared_ptr<User> user = std::make_shared<User>(name, surname, catalogue);
            std::cout << "Welcome " << user->getName() << " " << user->getSurname() << std::endl;
            showMenu(user);
            break;
        }
        case 2:
            return;
        default:
            std::cout << "Invalid choice" << std::endl;
    }
    start();
}

void MenuManager::showMenu(std::shared_ptr<User> user) {
    int choice;
    std::cout << "You can:" << std::endl;
    std::cout << "1. Create a new shopping list" << std::endl;
    std::cout << "2. Add an existing shopping list from the general catalogue" << std::endl;
    std::cout << "3. Delete a shopping list" << std::endl;
    std::cout << "4. Add an item" << std::endl;
    std::cout << "5. Remove an item" << std::endl;
    std::cout << "6. Sign an item bought" << std::endl;
    std::cout << "7. Reorder your shopping lists" << std::endl;
    std::cout << "8. See all your shopping lists" << std::endl;
    std::cout << "9. See a single list by name" << std::endl;
    std::cout << "10. See all the shopping lists in the general catalogue" << std::endl;
    std::cout << "11. Exit" << std::endl;
    std::cin >> choice;

    switch (choice) {
        case 1: {
            std::cout << "List name:" << std::endl;
            std::string name;
            std::cin >> name;
            user->createShoppingList(name);
            showMenu(user);
            break;
        }
        case 2: {
            std::cout << "Insert the name of the list you want to add:" << std::endl;
            std::string name;
            std::cin >> name;
            user->addShoppingList(name);
            showMenu(user);
        }
        case 3: {
            std::cout << "Insert the name of the list you want to delete:" << std::endl;
            std::string name;
            std::cin >> name;
            user->deleteShoppingList(name);
            showMenu(user);
        }
        case 4: {
            std::cout << "Insert the name of the list you want to add an item to:" << std::endl;
            std::string name;
            std::cin >> name;
            std::cout << "Insert the category of the item you want to add:" << std::endl;
            std::string category;
            std::cin >> category;
            std::cout << "Insert the name of the item you want to add:" << std::endl;
            std::string itemName;
            std::cin >> itemName;
            std::cout << "Insert the quantity of the item you want to add:" << std::endl;
            int quantity;
            std::cin >> quantity;
            std::cout << "Is it food? (1 for yes, 0 for no)" << std::endl;
            int food;
            std::cin >> food;
            if (food == 1) {
                std::cout << "Is it a fridge food? (1 for yes, 0 for no)" << std::endl;
                int inFridge;
                std::cin >> inFridge;
                std::cout << "Is it a frozen food? (1 for yes, 0 for no)" << std::endl;
                int frozen;
                std::cin >> frozen;
                std::cout << "Insert the kilos (optional, 0 for not provided):" << std::endl;
                int kilos;
                std::cin >> kilos;
                user->addItem(name, std::make_unique<FoodItem>(category, itemName, quantity, frozen, inFridge, kilos));
            } else
                user->addItem(name, std::make_unique<NotFoodItem>(category, itemName, quantity));
            showMenu(user);
        }
        case 5: {
            std::cout << "Insert the name of the list you want to remove an item from:" << std::endl;
            std::string name;
            std::cin >> name;
            std::cout << "Insert the category of the item you want to remove:" << std::endl;
            std::string category;
            std::cin >> category;
            std::cout << "Insert the name of the item you want to remove:" << std::endl;
            std::string itemName;
            std::cin >> itemName;
            user->removeItem(category, itemName, name);
            showMenu(user);
        }
        case 6: {
            std::cout << "Insert the name of the list you want to sign an item from:" << std::endl;
            std::string name;
            std::cin >> name;
            std::cout << "Insert the category of the item you want to sign:" << std::endl;
            std::string category;
            std::cin >> category;
            std::cout << "Insert the name of the item you want to sign:" << std::endl;
            std::string itemName;
            std::cin >> itemName;
            user->buyItem(category, itemName, name);
            showMenu(user);
        }
        case 7: {
            std::cout << "Insert the name of the list you want to reorder:" << std::endl;
            std::string name;
            std::cin >> name;
            std::cout << "Insert the categories in the order you want them to be: (end to stop)" << std::endl;
            std::list<std::string> categories;
            std::string category;
            while (std::cin >> category && category != "end") {
                categories.push_back(category);
            }
            user->reorderItem(categories, name);
            showMenu(user);
        }
        case 8: {
            user->printAllLists();
            showMenu(user);
        }
        case 9: {
            std::cout << "Insert the name of the list you want to see:" << std::endl;
            std::string name;
            std::cin >> name;
            user->printList(name);
            showMenu(user);
        }
        case 10: {
            user->showCatalogue();
            showMenu(user);
        }
        case 11:
            start();
    }
}
