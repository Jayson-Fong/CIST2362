//
//  Input.cpp
//  ConversionService
//
//  Created by Jayson Fong on 4/24/21.
//

#include "Input.hpp"
#include <iostream>
#include <limits>
#include "Config.hpp"
#include "Length.hpp"

// Requests a decimal number from the client
const long double Input::getDecimal() {
    long double value;
    bool failure;
    
    do {
        std::cout << "Enter a decimal number: ";
        std::cin >> value;

        // if input failure or outside of range
        failure = std::cin.fail() || !Length::doubleRange(Config::MIN_DECIMAL, Config::MAX_DECIMAL, value);
        if (failure) {
            std::cout << "Please enter a valid number between " << Config::MIN_DECIMAL << " and " << Config::MAX_DECIMAL << '.' << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        }
    } while (failure);
    
    return value;
}

// requests a hex string
const std::string Input::getHex() {
    std::string value;
    bool failure;
    
    do {
        std::cout << "Enter a hexadecimal string: ";
        std::cin >> value;
        
        // if input failure or too short/long
        failure = std::cin.fail() || !Length::stringLength(Config::MIN_HEX, Config::MAX_HEX, value);
        if (failure) {
            std::cout << "Please enter a valid hexadecimal string between " << Config::MIN_HEX << " and " << Config::MAX_HEX << " characters in length." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        }
    } while (failure);
    
    return value;
}
