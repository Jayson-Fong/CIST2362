//
//  Characterizer.cpp
//  PasswordService
//
//  Created by Jayson Fong on 4/30/21.
//

#include "Characterizer.hpp"

// Determines if a character is a special character
const bool Characterizer::isSpecial(const char character) {
    switch(character) {
        case '!': case '@': case '#':
        case '$': case '%': case '^':
        case '&': case '*': case '(':
        case ')': case '_': case '+':
            return true;
        default: return false;
    }
}

// Classifies the characters in the password
Characterizer::CharType* Characterizer::characterize(std::string password) {
    const char* passwordChar = password.c_str();
    Characterizer::CharType* charTypes = new CharType;
    charTypes->length = std::strlen(passwordChar);
    for (unsigned int charIndex = 0; charIndex < charTypes->length; charIndex = charIndex + 1) {
        if (std::isdigit(passwordChar[charIndex])) ++charTypes->numbers;
        else if (std::isupper(passwordChar[charIndex])) ++charTypes->uppercase;
        else if (std::islower(passwordChar[charIndex])) ++charTypes->lowercase;
        else if (Characterizer::isSpecial(passwordChar[charIndex])) ++charTypes->special;
    }
    return charTypes;
}
