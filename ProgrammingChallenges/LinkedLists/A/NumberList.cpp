//
//  NumberList.cpp
//  NumberList
//
//  Created by Jayson Fong on 3/27/21.
//

#include "NumberList.hpp"
#include <iostream>

NumberList::~NumberList() {
    ListNode* node = head;
    ListNode* next;
    while (node->next) {
        next = node->next;
        delete node;
        node = next;
    }
    delete node;
}

void NumberList::appendNode(double value) {
    ListNode* node = new ListNode;
    node->value = value;
    if (head == nullptr) {
        // If the list is empty, set new as head
        head = node;
    } else {
        // Else, traverse to end
        ListNode* traverseNode = head;
        while (traverseNode->next) {
            traverseNode = traverseNode->next;
        }
        traverseNode->next = node;
    }
}

void NumberList::insertNode(double value) {
    ListNode* node = new ListNode;
    node->value = value;
    if (head == nullptr) {
        // If list empty, set as new head
        head = node;
    } else {
        // Else, find first node with greater or equal value
        ListNode* traverseNode = head;
        ListNode* previous = nullptr;
        while (traverseNode->next && traverseNode->value < value) {
            previous = traverseNode;
            traverseNode = traverseNode->next;
        }
        
        if (previous == nullptr) {
            node->next = head;
            head = node;
        } else {
            node->next = traverseNode;
            previous->next = node;
        }
    }
}

void NumberList::deleteNode(double value) {
    // Check if empty
    if (head == nullptr) {
        return; // Do nothing.
    }
    
    ListNode* current = head;
    if (current->value == value) {
        // Check if first is the match
        head = head->next;
        delete current;
    } else {
        ListNode* previous = head;
        current = head->next;
        while (current != nullptr && current->value != value) {
            previous = current;
            current = current->next;
        }
        
        // If we found a match
        if (current != nullptr) {
            // Delete `current`
            previous->next = current->next;
            delete current;
        }
    }
}

void NumberList::displayList() const {
    ListNode* node = head;
    while (node != nullptr) {
        std::cout << node->value << std::endl;
        node = node->next;
    }
}
