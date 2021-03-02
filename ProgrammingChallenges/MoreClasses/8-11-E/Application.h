//
//  Application.h
//  PaperWriter
//
//  Created by Jayson Fong on 2/28/21.
//

#ifndef Application_h
#define Application_h

#include <iostream>
#include <string>
#include "InputManager.h"
#include "PaperWriter.h"
#include "GeneratorType.h"

class Application {
    
private:
        
    bool continueCheck() {
        return InputManager::getInteger("Continue?\n[1] Yes\n[0] No\nSelect Option") == 1;
    }
    
    GeneratorType getGeneratorType() {
        int choice;
        bool fail;
        
        do {
            displayChoices();
            choice = InputManager::getInteger("Select a Choice");
            fail = choice < 0 || choice > 1;
            
            if (fail) {
                std::cout << "Invalid Option" << std::endl;
            }
        } while (choice < 0 || choice > 1);
        
        switch (choice) {
            case 0:
            default:
                return GeneratorType::PARAGRAPH;
            case 1:
                return GeneratorType::TERM_PAPER;
        }
    }
    
    void displayChoices() {
        std::cout << "Generator Options:" << std::endl;
        std::cout << "[0] Paragraph (20 Sentences)" << std::endl;
        std::cout << "[1] Thesis (5 Paragraphs)" << std::endl;
    }
    
public:
    
    void run() {
        GeneratorType generatorType;
        do {
            generatorType = getGeneratorType();
            PaperWriter paperWriter(generatorType);
            paperWriter.run();
            // Run again if the user wants to
        } while(continueCheck());
    }
    
};

#endif /* Application_h */
