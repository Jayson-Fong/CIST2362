//
//  Password.hpp
//  PasswordService
//
//  Created by Jayson Fong on 4/29/21.
//

#ifndef Password_hpp
#define Password_hpp

#include <stdio.h>
#include <string>
#include "Characterizer.hpp"

class Password {
  
private:
    
public:
    
    enum Classification {
        WEAK, STRONG, VERY_SECURE
    };
    
    struct PasswordDetails {
        Password::Classification classification;
        Characterizer::CharType* detail;
    };
    
    // Verifies a password matches
    static const bool verifyHash(const std::string, const unsigned long);
    
    // Hashes a password
    static const unsigned long hash(const std::string);
    
    // Gets the classification of a password
    static const Password::Classification getClassification(const std::string);
    
    // Gets the classification of a password
    static const Password::Classification getClassification(const Characterizer::CharType*);
    
    // Returns a struct with the classification and summary of the password
    static const Password::PasswordDetails* getDetails(const std::string);
        
};

#endif /* Password_hpp */
