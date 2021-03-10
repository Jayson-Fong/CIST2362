//
//  main.cpp
//  DrinkMachineSimulator
//
//  Created by Jayson Fong on 3/8/21.
//

#include <iostream>
#include "Drink.hpp"
#include "ItemSet.hpp"
#include "DrinkMachine.hpp"

int main(int argc, const char * argv[]) {
    const unsigned short ITEM_COUNT = 5;
    
    ItemSet itemSet;
    itemSet.count = ITEM_COUNT;
    
    // Instantiate Items
    Item* items[ITEM_COUNT] = {
        new Drink("Cola", 0.75, 20),
        new Drink("Root Beer", 0.75, 20),
        new Drink("Lemon-Lime", 0.75, 20),
        new Drink("Grape Soda", 0.80, 20),
        new Drink("Cream Soda", 0.80, 20)
    };
    itemSet.items = items;
    
    DrinkMachine machine(itemSet);
    machine.run();

    return 0;
}
