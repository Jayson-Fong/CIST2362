//
//  DynamicQueue.hpp
//  ListManagementService
//
//  Created by Jayson Fong on 4/4/21.
//

#ifndef DynamicQueue_hpp
#define DynamicQueue_hpp

#include <stdio.h>

template <class T>
class DynamicQueue {
    
private:
    
    struct QueueNode {
        T value;
        QueueNode* nextPtr;
    };
    
    QueueNode* frontPtr;
    QueueNode* rearPtr;
    
public:
    
    // Constructor
    DynamicQueue() {
        this->frontPtr = nullptr;
        this->rearPtr = nullptr;
    }
    
    // Destructor
    ~DynamicQueue();
    
    // Queue Operations
    void enqueue(T);
    void dequeue(T &);
    bool isEmpty();
    void clear();

};

#endif /* DynamicQueue_hpp */
