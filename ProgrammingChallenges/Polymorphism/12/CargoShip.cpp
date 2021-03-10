//
//  CargoShip.cpp
//  Shipping
//
//  Created by Jayson Fong on 3/7/21.
//

#include <iostream>
#include "CargoShip.hpp"

CargoShip::CargoShip(const std::string iName, const std::string iYearBuilt, const unsigned int iTonnage) : Ship(iName, iYearBuilt) {
    this->tonnage = iTonnage;
}

const unsigned int CargoShip::getTonnage() {
    return tonnage;
}

void CargoShip::setTonnage(const unsigned int newTonnage) {
    tonnage = newTonnage;
}

void CargoShip::print() {
    std::cout << "Name: \"" << getName() << "\" Tonnage: " << getTonnage() << std::endl;
}
