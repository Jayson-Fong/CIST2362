//
//  Application.h
//  RandomNumberSet
//
//  Created by Jayson Fong on 3/1/21.
//

#ifndef Application_h
#define Application_h

#include <iostream>
#include <string>
#include "InputManager.h"
#include "RandomNumberSet.h"

class Application {
    
private:
        
    const bool continueCheck() {
        return InputManager::getInteger("Continue?\n[1] Yes\n[0] No\nSelect Option") == 1;
    }
    
    void processAndDisplay(RandomNumberSet &randomSet) {
        const unsigned short numValues = randomSet.getValueCount();
        
        randomSet.loadNumbers();
        
        std::cout << "Values:" << std::endl;
        const unsigned short* randomIntegers = randomSet.getRandomIntegers();
        for (unsigned short valueIndex = 0b0; valueIndex < numValues; valueIndex++) {
            std::cout << '\t' << *(randomIntegers + valueIndex) << std::endl;
        }
        
        std::cout << "Minimum: " << randomSet.getMinimum() << std::endl;
        std::cout << "Minimum: " << randomSet.getMaximum() << std::endl;
    }
    
public:
    
    void run() {
        unsigned short values, maximum;
        do {
            values = InputManager::getInteger("Number of Random Values", 1);
            maximum = InputManager::getInteger("Maximum Value", 0);
            RandomNumberSet randomSet(values, maximum);
            processAndDisplay(randomSet);
            // Run again if the user wants to
        } while(continueCheck());
    }
    
};

#endif /* Application_h */
