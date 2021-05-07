//
//  main.cpp
//  ListManagementService
//
//  Created by Jayson Fong on 4/4/21.
//

#include <iostream>
#include <string>
#include "Application.hpp"
#include "DynamicStack.hpp"
#include "DynamicQueue.hpp"

// Test Services

template <class T>
void stackTest(const std::string type, const T valueOne, const T valueTwo, const T valueThree) {
    std::cout << type << " DynamicStack Test" << std::endl;
    DynamicStack<T> stack;
    std::cout << "Pushing Values: " << valueOne << ", " << valueTwo << ", " << valueThree << std::endl;
    stack.push(valueOne);
    stack.push(valueTwo);
    stack.push(valueThree);
    std::cout << "Popping All Values:" << std::endl;
    
    T value;
    while (!stack.isEmpty()) {
        stack.pop(value);
        std::cout << "Got Value '" << value << "'!" << std::endl;
    }
    
    std::cout << "Finished Test (" << type << ')' << std::endl << std::endl;
}

template <class T>
void queueTest(const std::string type, const T valueOne, const T valueTwo, const T valueThree) {
    std::cout << type << " DynamicQueue Test" << std::endl;
    DynamicQueue<T> queue;
    std::cout << "Queueing Values: " << valueOne << ", " << valueTwo << ", " << valueThree << std::endl;
    queue.enqueue(valueOne);
    queue.enqueue(valueTwo);
    queue.enqueue(valueThree);
    std::cout << "Dequeuing All Values:" << std::endl;
    
    T value;
    while (!queue.isEmpty()) {
        queue.dequeue(value);
        std::cout << "Got Value '" << value << "'!" << std::endl;
    }
    
    std::cout << "Finished Test (" << type << ')' << std::endl << std::endl;
}

// Process Services

void stackExample() {
    stackTest("Integer", 5, 3, 9);
    stackTest("Float", 3.6f, 5.7f, 8.2f);
    stackTest("Long", 48l, 19l, 79l);
    stackTest("String", std::string("hello"), std::string("welcome"), std::string("hi"));
    stackTest("Character Arrays", "Jake", "Jose", "Jacob");
}

void queueExample() {
    queueTest("Integer", 3, 6, 1);
    queueTest("Float", 2.8f, 1.3f, 9.6f);
    queueTest("Long", 89l, 46l, 95l);
    queueTest("String", std::string("hello"), std::string("welcome"), std::string("hi"));
    queueTest("Character Arrays", "John", "Jesse", "Jenny");
}

void process() {
    stackExample();
    queueExample();
}

int main() {
    Application app(&process, "Stack and Queue Example Service");
    app.start();
    
    return 0;
}
