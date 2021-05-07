//
//  Length.hpp
//  ConversionService
//
//  Created by Jayson Fong on 4/24/21.
//

#ifndef Length_hpp
#define Length_hpp

#include <stdio.h>
#include <string>

class Length {
    
public:
    
    // Verify a string's length is in a range
    static const bool stringLength(const unsigned int, const unsigned int, const std::string);
    
    // Verify a long double's value is within a range
    static const bool doubleRange(const long double, const long double, const long double);
    
};

#endif /* Length_hpp */
