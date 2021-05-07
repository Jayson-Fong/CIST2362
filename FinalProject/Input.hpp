//
//  Input.hpp
//  ConversionService
//
//  Created by Jayson Fong on 4/24/21.
//

#ifndef Input_hpp
#define Input_hpp

#include <stdio.h>
#include <string>

class Input {
  
public:
    
    // requests a decimal num from the client
    static const long double getDecimal();
    
    // requests a hex string from the client
    static const std::string getHex();
    
};

#endif /* Input_hpp */
