//
//  Decision.cpp
//  ConversionService
//
//  Created by Jayson Fong on 4/24/21.
//

#include "Decision.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>

// destructor
Decision::~Decision() {
    ChoiceNode* node = head;
    ChoiceNode* next;
    while (node->next) {
        next = node->next;
        delete node;
        node = next;
    }
    delete node;
}

// add choice to linked list
void Decision::appendNode(std::string value) {
    ChoiceNode* node = new ChoiceNode;
    node->value = value;
    if (head == nullptr) {
        // If the list is empty, set new as head
        head = node;
    } else {
        // Else, traverse to end
        ChoiceNode* traverseNode = head;
        while (traverseNode->next) {
            traverseNode = traverseNode->next;
        }
        traverseNode->next = node;
    }
    ++this->choiceCount;
}

// show choices available
void Decision::displayChoices() const {
    ChoiceNode* node = head;
    unsigned int index = 1;
    while (node != nullptr) {
        std::cout << '[' << index++ << "] " << node->value << std::endl;
        node = node->next;
    }
}

// ask the client for a choice and validate
unsigned int Decision::choose() {
    unsigned int decision;
    bool failure;
    
    if (this->choiceCount == 0) {
        throw std::out_of_range("No Decision Choices Available in Pool");
    }
    
    do {
        this->displayChoices();
        std::cout << "Select an Option: ";
        std::cin >> decision;
        std::cout << std::endl;
        
        failure = std::cin.fail() || decision < 1 || decision > this->choiceCount;
        
        if (failure) {
            failure = true;
            std::cout << "Invalid input provided. Please select from the given choices." << std::endl << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        }
        
    } while (failure);
    
    return decision;
}
