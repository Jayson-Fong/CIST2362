//
//  DynamicQueue.cpp
//  ListManagementService
//
//  Created by Jayson Fong on 4/4/21.
//

#include "DynamicQueue.hpp"
#include <stdexcept>
#include <string>

// Destructor
template <class T>
DynamicQueue<T>::~DynamicQueue() {
    this->clear();
}

// Queue Operations
template <class T>
void DynamicQueue<T>::enqueue(T value) {
    DynamicQueue<T>::QueueNode* newNode = new DynamicQueue<T>::QueueNode;
    newNode->nextPtr = nullptr;
    newNode->value = value;
    
    if (this->rearPtr == nullptr) {
        this->frontPtr = newNode;
        this->rearPtr = newNode;
    } else {
        this->rearPtr->nextPtr = newNode;
        this->rearPtr = newNode;
    }
}

template <class T>
void DynamicQueue<T>::dequeue(T &value) {
    DynamicQueue<T>::QueueNode* tempPtr;
    
    // Check if first exists
    if (this->isEmpty()) {
        throw std::runtime_error("Empty Queue Exception");
    }
    
    if (this->frontPtr == this->rearPtr) {
        this->rearPtr = nullptr;
    }
    
    value = this->frontPtr->value;
    tempPtr = this->frontPtr->nextPtr;
    delete this->frontPtr;
    this->frontPtr = tempPtr;
}

template <class T>
bool DynamicQueue<T>::isEmpty() {
    return this->frontPtr == nullptr;
}

template <class T>
void DynamicQueue<T>::clear() {
    DynamicQueue<T>::QueueNode* iterationNodePtr, * nextNodePtr;
    
    iterationNodePtr = this->frontPtr;
    while (iterationNodePtr != nullptr) {
        nextNodePtr = iterationNodePtr->nextPtr;
        delete iterationNodePtr;
        iterationNodePtr = nextNodePtr;
    }
    
    this->frontPtr = nullptr;
    this->rearPtr = nullptr;
}

// Compile
template class DynamicQueue<int>;
template class DynamicQueue<float>;
template class DynamicQueue<long>;
template class DynamicQueue<std::string>;
template class DynamicQueue<char const*>;
