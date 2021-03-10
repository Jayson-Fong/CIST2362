//
//  DrinkMachine.cpp
//  DrinkMachineSimulator
//
//  Created by Jayson Fong on 3/8/21.
//

#include <iostream>
#include "DrinkMachine.hpp"
#include "ItemSet.hpp"
#include "InputManager.hpp"
#include "ItemSet.hpp"
#include "Order.hpp"
#include "NumberFormat.hpp"

// Displays purchasing options.
void DrinkMachine::displayOptions() {
    std::cout << "Operations and Items:" << std::endl;
    for (unsigned short choiceIndex = 0; choiceIndex < itemSet.count; choiceIndex++) {
        std::cout << "\t[" << choiceIndex << "] " << "Purchase " << itemSet.items[choiceIndex]->getName() << " for " << NumberFormat::moneyFormat(itemSet.items[choiceIndex]->getCost()) << std::endl;
    }
    std::cout << "\t[" << itemSet.count << "] Quit" << std::endl;
}

// Gets what the client wants to do or buy.
unsigned short DrinkMachine::nextItemRequest() {
    displayOptions();
    unsigned short choice;
    bool fail;
    do {
        choice = InputManager::getInteger("Select an Operation or Item to Purchase");
        fail = choice < 0 || choice > itemSet.count;
        if (fail) {
            std::cout << "Invalid Choice Selected!" << std::endl;
        }
    } while (fail);
    return choice;
}

// Display revenue.
void DrinkMachine::finalize() {
    std::cout << "Thank you for shopping with us today." << std::endl;
    std::cout << std::endl << "Total Revenue: $" << revenue << std::endl << std::endl;
}

// Process a purchase.
void DrinkMachine::purchase(const unsigned short itemId) {
    Item* item = itemSet.items[itemId];
    Order order(item, revenue);
    order.process();
}

void DrinkMachine::welcomeService() {
    std::cout << "Welcome to the Fong Drink Machine Simulator!" << std::endl << std::endl;
}

DrinkMachine::DrinkMachine(const ItemSet iItemSet) {
    itemSet = iItemSet;
    revenue = 0;
}

void DrinkMachine::run() {
    welcomeService();
    
    unsigned short choice;
    do {
        choice = nextItemRequest();
        // Process an Item Purchase
        // The exit command is the same choice as the item set count.
        if (choice < itemSet.count) {
            purchase(choice);
        }
    } while (choice != itemSet.count);
    finalize();
}
