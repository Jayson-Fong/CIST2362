//
//  Item.cpp
//  DrinkMachineSimulator
//
//  Created by Jayson Fong on 3/8/21.
//

#include <iostream>
#include "Item.hpp"

Item::Item(const std::string iName, const double iPrice, const unsigned int iStock) {
    name = iName;
    cost = iPrice;
    stock = iStock;
}

const std::string Item::getName() const {
    return name;
}

const double Item::getCost() const {
    return cost;
}

const unsigned int Item::getStock() const {
    return stock;
}

void Item::setName(const std::string newName) {
    name = newName;
}

void Item::setCost(const double newCost) {
    cost = newCost;
}

void Item::setStock(const unsigned int newStock) {
    stock = newStock;
}

const bool Item::dispense(const unsigned int amount) {
    if (stock < amount) {
        return false;
    }
    stock -= amount;
    return true;
}

void Item::restock(const unsigned int amount) {
    stock += amount;
}
