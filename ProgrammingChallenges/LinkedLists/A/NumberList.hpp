//
//  NumberList.hpp
//  NumberList
//
//  Created by Jayson Fong on 3/27/21.
//

#ifndef NumberList_hpp
#define NumberList_hpp

#include <stdio.h>

class NumberList {
       
private:
    
    struct ListNode {
        double value;
        struct ListNode* next = nullptr;
    };
    
    ListNode* head;
    
public:
    
    // Constructor
    NumberList() {
        head = nullptr;
    }
    
    // Destructor
    ~NumberList();
    
    void appendNode(double);
    void insertNode(double);
    void deleteNode(double);
    void displayList() const;
    
};

#endif /* NumberList_hpp */
