//
//  Length.cpp
//  ConversionService
//
//  Created by Jayson Fong on 4/24/21.
//

#include "Length.hpp"

// Verify a string's length is in a range
const bool Length::stringLength(const unsigned int min, const unsigned int max, const std::string str) {
    return str.length() >= min && str.length() <= max;
}

// Verify a long double's value is within a range
const bool Length::doubleRange(const long double min, const long double max, const long double num) {
    return num >= min && num <= max;
}
