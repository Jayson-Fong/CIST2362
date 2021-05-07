//
//  Convert.hpp
//  ConversionService
//
//  Created by Jayson Fong on 4/24/21.
//

#ifndef Convert_hpp
#define Convert_hpp

#include <stdio.h>
#include <ctype.h>
#include <string>
#include <tgmath.h>
#include <stdexcept>

class Convert {
    
private:
    
    static const std::string underReturn(unsigned int &, unsigned int);
    
    static const std::string underReturn_ieee754(long double &);
    
    static const bool ieee754exp_r(long double);
    
    static const std::string ieee754exp_s(int);
    
    static const int ieee754exp(long double);
    
    static const std::string ieee754sig(const long double);
    
    static const std::string ieee754man(const long double, const int, const short);
    
public:
    
    // Convert a decimal num to ieee754 and return the ieee754 representation
    static const std::string decimalToIEEE754(const long double);
    
    // Takes hex and returns a binary string equiv
    static const std::string hexToBinary(std::string);
    
    // Takes a hex char and returns a decimal equiv
    static const unsigned int hexToDecimal(char);
    
    // Takes a decimal num and return a binary nibble string
    static const std::string decimalToNibble(unsigned int);
    
    // Takes a decimal num and return a binary byte string
    static const std::string decimalToByte(unsigned int);
    
    // Convert a decimal to a byte with no leading 0s, reversed
    static const std::string decimalToByteShort(double);
    
};

#endif /* Convert_hpp */
