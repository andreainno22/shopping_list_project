//
// Created by andrea on 26/09/2023.
//

#include "MenuManager.h"
#include "NotFoodItem.h"

// manage the user log

void MenuManager::start() {
    while (sessionOpen) {
        int choice;
        std::cout << "Welcome to the Shopping List Manager!" << std::endl;
        std::cout << "What do you want to do?" << std::endl;
        std::cout << "1. Login" << std::endl;
        std::cout << "2. Exit" << std::endl;
        while (!(std::cin >> choice)) {
            std::cout << "1. Login" << std::endl;
            std::cout << "2. Exit" << std::endl;
            std::cout << "Wrong format." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        switch (choice) {
            case 1: {
                std::string name, surname;
                std::cout << "Insert your name: ";
                std::cin >> name;
                std::cout << "Insert your surname: ";
                std::cin >> surname;
                std::shared_ptr<User> user = std::make_shared<User>(name, surname, catalogue);
                std::cout << "Welcome " << user->getName() << " " << user->getSurname() << std::endl;
                logged = true;
                while (logged)
                    showMenu(user);
                break;
            }
            case 2: {
                sessionOpen = false;
                break;
            }
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    }
}


// shows the menu and manage the user choice

void MenuManager::showMenu(const std::shared_ptr<User> &user) {
    int choice;
    std::cout << "You can:" << std::endl;
    std::cout << "1. Create a new shopping list" << std::endl;
    std::cout << "2. Add an existing shopping list from the general catalogue" << std::endl;
    std::cout << "3. Delete a shopping list" << std::endl;
    std::cout << "4. Add an item" << std::endl;
    std::cout << "5. Remove an item" << std::endl;
    std::cout << "6. Sign an item bought" << std::endl;
    std::cout << "7. See all your shopping lists" << std::endl;
    std::cout << "8. See a single list by name" << std::endl;
    std::cout << "9. See all the shopping lists in the general catalogue" << std::endl;
    std::cout << "10. Exit" << std::endl;
    std::cin >> choice;

    switch (choice) {
        case 1: {
            std::cout << "List name:" << std::endl;
            std::string name;
            std::cin >> name;
            user->createShoppingList(name);
            break;
        }
        case 2: {
            std::cout << "Insert the name of the list you want to add:" << std::endl;
            std::string name;
            std::cin >> name;
            user->addShoppingList(name);
            break;
        }
        case 3: {
            std::cout << "Insert the name of the list you want to delete:" << std::endl;
            std::string name;
            std::cin >> name;
            user->deleteShoppingList(name);
            break;
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
            if (!(std::cin >> quantity)) {
                std::cout << "Wrong format." << std::endl;
                std::cin.clear(); // Resetta lo stato di errore di cin
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n'); // Ignora il resto dell'input fino a quando non premi "Invio"
                break;
            }
            std::cout << "Is it food? (1 for yes, 0 for no)" << std::endl;
            int food;
            if (!(std::cin >> food)) {
                std::cout << "Wrong format." << std::endl;
                std::cin.clear(); // Resetta lo stato di errore di cin
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            if (food == 1) {
                std::cout << "Is it a fridge food? (1 for yes, 0 for no)" << std::endl;
                int inFridge;
                if (!(std::cin >> inFridge)) {
                    std::cout << "Wrong format." << std::endl;
                    std::cin.clear(); // Resetta lo stato di errore di cin
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                    '\n'); // Ignora il resto dell'input fino a quando non premi "Invio"
                    break;
                }
                std::cout << "Is it a frozen food? (1 for yes, 0 for no)" << std::endl;
                int frozen;
                if (!(std::cin >> frozen)) {
                    std::cout << "Wrong format." << std::endl;
                    std::cin.clear(); // Resetta lo stato di errore di cin
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                    '\n'); // Ignora il resto dell'input fino a quando non premi "Invio"
                    break;
                }
                std::cout << "Insert the kilos (optional, 0 for not provided):" << std::endl;
                int kilos;
                if (!(std::cin >> kilos)) {
                    std::cout << "Wrong format." << std::endl;
                    std::cin.clear(); // Resetta lo stato di errore di cin
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                    '\n'); // Ignora il resto dell'input fino a quando non premi "Invio"
                    break;
                }
                user->addItem(name, std::make_unique<FoodItem>(category, itemName, quantity, frozen, inFridge, kilos));
            } else
                user->addItem(name, std::make_unique<NotFoodItem>(category, itemName, quantity));
            break;
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
            break;
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
            break;
        }

        case 7: {
            user->printAllLists();
            break;
        }
        case 8: {
            std::cout << "Insert the name of the list you want to see:" << std::endl;
            std::string name;
            std::cin >> name;
            user->printList(name);
            break;
        }
        case 9: {
            user->showCatalogue();
            break;
        }
        case 10: {
            logged = false;
            break;
        }
        default:
            std::cout << "Invalid choice" << std::endl;
    }
}
