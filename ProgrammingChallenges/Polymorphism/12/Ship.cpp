//
//  Ship.cpp
//  Shipping
//
//  Created by Jayson Fong on 3/7/21.
//

#include <iostream>
#include "Ship.hpp"

Ship::Ship(const std::string name, const std::string yearBuilt) {
    this->name = name;
    this->yearBuilt = yearBuilt;
}

const std::string Ship::getName() {
    return name;
}

const std::string Ship::getYearBuilt() {
    return yearBuilt;
}

void Ship::setName(const std::string newName) {
    name = newName;
}

void Ship::setYearBuilt(const std::string newYearBuilt) {
    yearBuilt = newYearBuilt;
}

void Ship::print() {
    std::cout << "Name: \"" << getName() << "\" Year Built: " << getYearBuilt() << std::endl;
}
