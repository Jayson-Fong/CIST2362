//
//  InputManager.hpp
//  DrinkMachineSimulator
//
//  Created by Jayson Fong on 3/8/21.
//

#ifndef InputManager_hpp
#define InputManager_hpp

#include <stdio.h>
#include <iostream>
#include <string>

class InputManager {
    
public:
    
    static const int getInteger(const std::string);
    static const double getDouble(const std::string);
    
};

#endif /* InputManager_hpp */
