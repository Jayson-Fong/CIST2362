//
//  InputManager.h
//  PaperWriter
//
//  Created by Jayson Fong on 2/28/21.
//

#ifndef InputManager_h
#define InputManager_h

#include <iostream>
#include <string>

class InputManager {
    
public:
    
    static int getInteger(std::string message) {
        int inputValue;
        bool fail;
        
        do {
            std::cout << message << ": ";
            std::cin >> inputValue;
            
            // If there's an error
            fail = std::cin.fail();
            if (fail) {
                std::cout << "Please enter a valid integer." << std::endl;
                // Clear input
                std::cin.clear();
                std::cin.ignore(INT8_MAX, '\n');
            }
        } while(fail);
        
        return inputValue;
    }
    
};

#endif /* InputManager_h */
