//
//  InputManager.cpp
//  DrinkMachineSimulator
//
//  Created by Jayson Fong on 3/8/21.
//

#include "InputManager.hpp"
#include <limits>

const int InputManager::getInteger(const std::string message) {
    int inputValue;
    bool fail;
    
    do {
        std::cout << message << ": ";
        std::cin >> inputValue;
        
        // Check for an error
        fail = std::cin.fail();
        if (fail) {
            std::cout << "Please enter a valid integer." << std::endl;
            // Clear input on error
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        }
    } while(fail);
    
    return inputValue;
}

const double InputManager::getDouble(const std::string message) {
    double inputValue;
    bool fail;
    
    do {
        std::cout << message << ": ";
        std::cin >> inputValue;
        
        // Check for an error
        fail = std::cin.fail();
        if (fail) {
            std::cout << "Please enter a valid double." << std::endl;
            // Clear input on error
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        }
    } while(fail);
    
    return inputValue;
}
