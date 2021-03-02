//
//  InputManager.h
//  RandomNumberSet
//
//  Created by Jayson Fong on 3/1/21.
//

#ifndef InputManager_h
#define InputManager_h

class InputManager {
    
public:
    
    const static int getInteger(const std::string message) {
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
    
    const static int getInteger(const std::string message, const int minValue) {
        int inputValue;
        bool fail;
        
        do {
            inputValue = InputManager::getInteger(message);
            
            fail = inputValue < minValue;
            if (fail) {
                std::cout << "Please enter an integer larger than " << minValue << std::endl;
            }
        } while(fail);
        
        return inputValue;
    }
    
};

#endif /* InputManager_h */
