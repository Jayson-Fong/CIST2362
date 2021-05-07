//
//  Characterizer.hpp
//  PasswordService
//
//  Created by Jayson Fong on 4/30/21.
//

#ifndef Characterizer_hpp
#define Characterizer_hpp

#include <stdio.h>
#include <string>
#include <cctype>

class Characterizer {
  
private:
    
    // Determines if a character is a special character
    static const bool isSpecial(const char);
    
public:
    
    struct CharType {
        unsigned long length = 0;
        unsigned int numbers = 0;
        unsigned int special = 0;
        unsigned int uppercase = 0;
        unsigned int lowercase = 0;
    };
    
    // Creates a CharType based on the characters in the string
    static CharType* characterize(std::string);
    
};

#endif /* Characterizer_hpp */
