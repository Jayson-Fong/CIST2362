//
//  CruiseShip.cpp
//  Shipping
//
//  Created by Jayson Fong on 3/7/21.
//

#include "CruiseShip.hpp"
#include <string>
#include <iostream>

CruiseShip::CruiseShip(const std::string iName, const std::string iYearBuilt, const unsigned int iMaxPassengers) : Ship(iName, iYearBuilt) {
    this->maxPassengers = iMaxPassengers;
}

const unsigned int CruiseShip::getMaxPassengers() {
    return maxPassengers;
}

void CruiseShip::setMaxPassengers(const unsigned int newMaxPassengers) {
    maxPassengers = newMaxPassengers;
}

void CruiseShip::print() {
    std::cout << "Name: \"" << getName() << "\" Max Passengers: " << getMaxPassengers() << std::endl;
}
