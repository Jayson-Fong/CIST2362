//
//  main.cpp
//  ConversionService
//
//  Created by Jayson Fong on 4/24/21.
//

#include <iostream>
#include <stdexcept>
#include <limits>
#include "Application.hpp"
#include "Decision.hpp"
#include "Input.hpp"
#include "Convert.hpp"

void decimalToIEEE754() {
    // get number
    const long double decimal = Input::getDecimal();
    // convert number to ieee754
    const std::string binary = Convert::decimalToIEEE754(decimal);
    // display result
    std::cout << "The IEEE-754 representation of " << decimal << " is: " << binary << std::endl;
}

void hexadecimalToBinary() {
    // get the hex
    const std::string hex = Input::getHex();
    
    try {
        // convert the hex to binary
        const std::string binary = Convert::hexToBinary(hex);
        // display to client
        std::cout << "The conversion of '" << hex << "' to binary is: " << binary << std::endl;
    } catch (std::logic_error logicError) {
        // In case the string is invalid.
        std::cout << "The string provided is not a valid hexadecimal string. Did you select the correct converter?" << std::endl;
    }
}

// Determines which path the client wants to take
void decision() {
    static Decision* decision = nullptr;
    
    if (decision == nullptr) {
        decision = new Decision;
        // Set decision nodes
        decision->appendNode("Convert Decimal to IEEE-754"); // Option 1
        decision->appendNode("Convert Hexadecimal to Binary"); // Option 2
    }
    
    switch (decision->choose()) {
        case 1:
            decimalToIEEE754();
            break;
        case 2:
            hexadecimalToBinary();
            break;
        default:
            // A (should be) impossible choice
            throw std::logic_error("Broken Choice Pipeline");
    }
}

// Run our looping service
void process() {
    decision();
}

int main() {
    // Start the application
    Application app(&process, "the converter");
    app.start();
    
    return 0;
}
