//
//  Config.hpp
//  ConversionService
//
//  Created by Jayson Fong on 4/24/21.
//

#ifndef Config_hpp
#define Config_hpp

#include <stdio.h>

class Config {
    
public:
    
    // HEXADECIMAL INPUTS (See Input)
    static const unsigned int MIN_HEX = 1;
    static const unsigned int MAX_HEX = 20;
    
    // DECIMAL INPUTS (See Input)
    static constexpr long double MIN_DECIMAL = -1000;
    static constexpr long double MAX_DECIMAL = 1000;
    
};

#endif /* Config_hpp */
