//
//  DynamicStack.hpp
//  ListManagementService
//
//  Created by Jayson Fong on 4/4/21.
//

#ifndef DynamicStack_hpp
#define DynamicStack_hpp

#include <stdio.h>

template <class T>
class DynamicStack {
    
private:
    
    struct StackNode {
        T value;
        StackNode* nextPtr;
    };
    
    StackNode* topPtr;
    
public:
    
    // Constructor
    DynamicStack() {
        this->topPtr = nullptr;
    }
    
    // Destructor
    ~DynamicStack();
    
    // Operations
    void push(T);
    void pop(T &);
    bool isEmpty();
    
};

#endif /* DynamicStack_hpp */
