//
//  DrinkMachine.hpp
//  DrinkMachineSimulator
//
//  Created by Jayson Fong on 3/8/21.
//

#ifndef DrinkMachine_hpp
#define DrinkMachine_hpp

#include <stdio.h>
#include <string>
#include "ItemSet.hpp"
#include "Item.hpp"
#include "InputManager.hpp"

class DrinkMachine {
  
private:
    
    ItemSet itemSet;
    double revenue;
    
    unsigned short nextItemRequest();
    void displayOptions();
    void finalize();
    void purchase(const unsigned short);
    void welcomeService();
    
public:
    
    DrinkMachine(const ItemSet);
    void run();
    
};

#endif /* DrinkMachine_hpp */
