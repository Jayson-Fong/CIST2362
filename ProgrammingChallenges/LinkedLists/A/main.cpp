//
//  main.cpp
//  NumberList
//
//  Created by Jayson Fong on 3/27/21.
//

#include <iostream>
#include "NumberList.hpp"
#include "Application.hpp"

void appendProcess(NumberList &list) {
    std::cout << std::endl << "Appending 5 Values..." << std::endl;
    list.appendNode(2.5);
    list.appendNode(7.9);
    list.appendNode(12.6);
    list.appendNode(25.8);
    list.appendNode(22.7);
    std::cout << "Result:" << std::endl;
    list.displayList();
}

void insertProcess(NumberList &list) {
    std::cout << std::endl << "Inserting 3 Values..." << std::endl;
    list.insertNode(10.5);
    list.insertNode(15.6);
    list.insertNode(16.5);
    std::cout << "Result:" << std::endl;
    list.displayList();
}

void deleteProcess(NumberList &list) {
    std::cout << std::endl << "Deleting 2 Values..." << std::endl;
    list.deleteNode(7.9);
    list.deleteNode(15.6);
    std::cout << "Result:" << std::endl;
    list.displayList();
}

void process() {
    NumberList list;
    appendProcess(list);
    insertProcess(list);
    deleteProcess(list);
}

int main(int argc, const char * argv[]) {
    Application app(&process, "Number List Service");
    app.start();
    
    return 0;
}
