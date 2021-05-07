//
//  Password.cpp
//  PasswordService
//
//  Created by Jayson Fong on 4/29/21.
//

#include "Password.hpp"
#include "Characterizer.hpp"

// Check if a password matches
const bool Password::verifyHash(const std::string password, const unsigned long knownHash) {
    return knownHash == std::hash<std::string>()(password);
}

// Hash a password
const unsigned long Password::hash(const std::string password) {
    return std::hash<std::string>()(password);
}

// Gets the password type
const Password::Classification Password::getClassification(const Characterizer::CharType* charType) {
    if (charType->length < 6
        || charType->numbers < 2
        || charType->special < 1
        || charType->uppercase < 1
        || charType->lowercase < 1) {
        return Password::Classification::WEAK;
    }
    
    if (charType->length > 7 && charType->special > 1) {
        return Password::Classification::VERY_SECURE;
    }
    
    return Password::Classification::STRONG;
}

// Get the detail summary and return the classification
const Password::Classification Password::getClassification(const std::string password) {
    const auto* charType = Characterizer::characterize(password);
    return Password::getClassification(charType);
}

// Returns a structure with the classification and details
const Password::PasswordDetails* Password::getDetails(const std::string password) {
    Password::PasswordDetails* details = new Password::PasswordDetails;
    Characterizer::CharType* charType = Characterizer::characterize(password);
    Password::Classification classification = getClassification(charType);
    details->classification = classification;
    details->detail = charType;
    return details;
}
