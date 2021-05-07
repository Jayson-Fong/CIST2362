//
//  Input.cpp
//  PasswordService
//
//  Created by Jayson Fong on 4/29/21.
//

#include "Input.hpp"
#include <string>
#include <iostream>

// Gets a string
const std::string Input::getString(const std::string message) {
    std::string value;
    bool failure;
    
    do {
        std::cout << message << ": ";
        std::cin >> value;
        
        // if input failure or too short/long
        failure = std::cin.fail();
        // if an error occured
        if (failure) {
            std::cout << "Sorry, there was an error retrieving your entry. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        }
    } while (failure);
    
    return value;
}
