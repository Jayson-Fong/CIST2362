//
//  DynamicStack.cpp
//  ListManagementService
//
//  Created by Jayson Fong on 4/4/21.
//

#include "DynamicStack.hpp"
#include <stdexcept>
#include <string>

// Destructor
template <class T>
DynamicStack<T>::~DynamicStack() {
    DynamicStack<T>::StackNode* iterationNodePtr, * nextNodePtr;
    
    iterationNodePtr = this->topPtr;
    while(iterationNodePtr != nullptr) {
        nextNodePtr = iterationNodePtr->nextPtr;
        delete iterationNodePtr;
        iterationNodePtr = nextNodePtr;
    }
}

template <class T>
void DynamicStack<T>::push(T value) {
    DynamicStack<T>::StackNode* newNodePtr = new StackNode;
    newNodePtr->nextPtr = nullptr;
    newNodePtr->value = value;
    
    // Assign new node as top
    newNodePtr->nextPtr = this->topPtr;
    this->topPtr = newNodePtr;
}

template<class T>
void DynamicStack<T>::pop(T &value) {
    DynamicStack<T>::StackNode* tempPtr = nullptr;
    
    // Check if empty
    if (this->isEmpty()) {
        throw std::runtime_error("Empty Stack Exception");
    }
    
    value = this->topPtr->value;
    tempPtr = this->topPtr->nextPtr;
    delete this->topPtr;
    this->topPtr = tempPtr;
}

template<class T>
bool DynamicStack<T>::isEmpty() {
    return this->topPtr == nullptr;
}

// Force Compile
template class DynamicStack<int>;
template class DynamicStack<float>;
template class DynamicStack<long>;
template class DynamicStack<std::string>;
template class DynamicStack<char const*>;
