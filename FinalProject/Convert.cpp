//
//  Convert.cpp
//  ConversionService
//
//  Created by Jayson Fong on 4/24/21.
//

#include "Convert.hpp"
#include <iostream>
#include <algorithm>
#include <string>
// If sub is less then carry, subtract sub from carry and return 1, else, return 0
// used for binary calculation
const std::string Convert::underReturn(unsigned int &carry, unsigned int sub) {
    if (carry >= sub) {
        carry = carry - sub;
        return "1";
    }
    return "0";
}

// if number is more than 1, subtract all wholes and return 1. else, return 0
const std::string Convert::underReturn_ieee754(long double &carry) {
    if (carry >= 1) {
        carry = carry - ((int) carry);
        return "1";
    }
    return "0";
}

// Determines if a number is in the desired range
const bool Convert::ieee754exp_r(long double num) {
    return !(num >= 1 && num <= 2);
}

// Converts a exponent to ieee754 form (adding 127)
const std::string Convert::ieee754exp_s(int exponent) {
    return Convert::decimalToByte(exponent + 127);
}

// calculate the mantissa
const int Convert::ieee754exp(long double num) {
    num = std::abs(num);
    unsigned int exponent = 0;
    // if less than 1 (divide by 2 to the negative exponent)
    if (num < 1) {
        for (exponent = -1; Convert::ieee754exp_r(num / pow(2, exponent)) && exponent < -128; exponent--);
    } else {
        // if more than or equal to 1
        for (exponent = 1; Convert::ieee754exp_r(num / pow(2, exponent)) && exponent < 128; exponent++);
    }
    
    return exponent;
}

// Determines if a number is positive and returns the representation
const std::string Convert::ieee754sig(const long double num) {
    return (num < 0 ? "1" : "0");
}

// Calculates the mantissa
const std::string Convert::ieee754man(const long double num, const int exponent, const short lead) {
    std::string mantissa;

    long double carry = std::abs(num);
    // run for each bit
    for (unsigned short mantissaIndex = 0; mantissaIndex < 23 - lead; mantissaIndex++) {
        carry *= 2;
        mantissa += Convert::underReturn_ieee754(carry);
    }
    
    return mantissa;
}

// compile ieee754 representation together
const std::string Convert::decimalToIEEE754(const long double number) {
    std::string representation, lead;
    int exponent;
    
    // add sign
    representation += Convert::ieee754sig(number);
    // add exponent
    exponent = Convert::ieee754exp(number);
    representation += Convert::ieee754exp_s(exponent);
    // add whole number
    lead = Convert::decimalToByteShort(number).substr(1);
    representation += lead;
    // add decimal portion
    representation += Convert::ieee754man(number - (int) number, exponent, lead.length());
    
    return representation;
}

// convert hex to binary string
const std::string Convert::hexToBinary(std::string hexChars) {
    std::string binary;
    
    unsigned int decimal;
    for (unsigned int nibbleIndex = 0; nibbleIndex < hexChars.length(); nibbleIndex++) {
        decimal = hexToDecimal(hexChars.at(nibbleIndex));
        binary += decimalToNibble(decimal);
    }
    
    return binary;
}

// convert hex to a decimal number
const unsigned int Convert::hexToDecimal(char hexChar) {
    hexChar = std::tolower(hexChar);
    unsigned int decimal;
    
    // numbers 0 - 9 in ASCII
    if (hexChar > 47 && hexChar < 58) decimal = hexChar - 48;
    // characters a - f in ASCII
    else if (hexChar > 96 && hexChar < 106) decimal = hexChar - 87;
    // any other character
    else throw std::invalid_argument("Invalid Hex Character");

    return decimal;
}

// convert a decimal number to a binary nibble
const std::string Convert::decimalToNibble(unsigned int decimal) {
    static unsigned short binRep[] = {8, 4, 2, 1};
    
    unsigned int carry = decimal;
    
    // 4 bits
    std::string nibble;
    // If more than or equal to pair in binRep, subtract the pair from carry and append 1. Else, maintain and append 0.
    for (unsigned short number : binRep) {
        nibble += Convert::underReturn(carry, number);
    }
    
    return nibble;
}

// convert a decimal number to a byte
const std::string Convert::decimalToByte(unsigned int decimal) {
    static unsigned short binRep[] = {128, 64, 32, 16, 8, 4, 2, 1};
    
    unsigned int carry = decimal;
    
    std::string byte;
    // If more than or equal to pair in binRep, subtract the pair from carry and append 1. Else, maintain and append 0.
    for (unsigned short number : binRep) {
        byte += Convert::underReturn(carry, number);
    }
    
    return byte;
}

// convert a decimal to a binary string reversed without leading
const std::string Convert::decimalToByteShort(double num) {
    unsigned int whole = (unsigned int) std::abs(num);
    unsigned int carry = whole;
    std::string binary;
    
    // Creates a backwards binary string
    do {
        if (carry % 2 == 1) {
            binary += "1";
        } else {
            binary += "0";
        }
        carry = carry / 2;
    } while (carry != 0);
    
    // Reverse the string back because creating it above makes it reversed
    std::reverse(binary.begin(), binary.end());
            
    return binary;
}
