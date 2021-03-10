//
//  Order.cpp
//  DrinkMachineSimulator
//
//  Created by Jayson Fong on 3/8/21.
//

#include <iostream>
#include <cmath>
#include "Order.hpp"
#include "InputManager.hpp"
#include "NumberFormat.hpp"

// Display an item
void Order::displayItem() {
    std::cout << std::endl << "You are purchasing: " << std::endl;
    std::cout << '\t' << *orderItem << std::endl << std::endl;
}

void Order::abort() {
    std::cout << "Order cancelled." << std::endl;
}

/**
    Gets the amount of payment from the customer.
    Rejects if the amount is too little, negative, or over a dollar.
 */
const double Order::getPayment() {
    double payment;
    bool inputFail, priceFail;
    do {
        displayItem();
        payment = InputManager::getDouble("Payment Amount (USD)");
        inputFail = payment < 0 || payment > 1;
        
        // If payment under 0
        if (inputFail) {
            std::cout << "Your payment cannot be negative or be more than a dollar." << std::endl;
        }
        
        // On exit request
        if (payment == 0) {
            abort();
            return 0;
        }
        
        // If insufficient amount
        priceFail = payment < orderItem->getCost();
        if (!inputFail && priceFail) {
            std::cout << "Your payment is insufficient. Please insert at least the amount of funds requested. Change returned." << std::endl;
            std::cout << "To chancel this order, enter $0." << std::endl;
        }
    } while (inputFail || priceFail);
    
    return payment;
}

// Show change due
void Order::showChange(const double changeDue) {
    std::cout << "Your Change is: " << NumberFormat::moneyFormat(changeDue) << std::endl << std::endl;
}

// Out of stock error
void Order::outOfStock() {
    std::cout << "Sorry, the product you requested is out of stock." << std::endl;
}

void Order::dispenseNotify() {
    std::cout << "Item dispensed!" << std::endl;
}

void Order::process() {
    if (orderItem->getStock() < 1) {
        outOfStock();
        return;
    }
    
    const double payment = getPayment();
    
    // Cancel Order
    if (payment == 0) {
        return;
    }
    
    // Calculate Change Due
    const double change = payment - orderItem->getCost();
    revenue += orderItem->getCost();
    orderItem->dispense(1);
    dispenseNotify();
    
    showChange(change);
}

Order::Order(Item* iItem, double &revenue) : revenue(revenue) {
    orderItem = iItem;
}
