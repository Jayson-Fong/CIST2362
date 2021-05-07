//
//  Decision.hpp
//  ConversionService
//
//  Created by Jayson Fong on 4/24/21.
//

#ifndef Decision_hpp
#define Decision_hpp

#include <stdio.h>
#include <string>

class Decision {
  
private:
    
    struct ChoiceNode {
        std::string value;
        struct ChoiceNode* next = nullptr;
    };
    
    ChoiceNode* head;
    unsigned int choiceCount;
    
public:
    
    // Constructor
    Decision() {
        this->head = nullptr;
        this->choiceCount = 0;
    }
    
    // Destructor
    ~Decision();
    
    // add a choice
    void appendNode(std::string);
    // display choices
    void displayChoices() const;
    // have the client choose a choice
    unsigned int choose();
    
};

#endif /* Decision_hpp */
