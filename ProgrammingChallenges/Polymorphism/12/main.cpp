//
//  main.cpp
//  Shipping
//
//  Created by Jayson Fong on 3/7/21.
//

#include <iostream>
#include "Ship.hpp"
#include "CruiseShip.hpp"
#include "CargoShip.hpp"

void displayShips(Ship* [], const unsigned int);

/**
  Displays ship details
 */
void displayShips(Ship* ships[], const unsigned int SHIP_COUNT) {
    for (unsigned int shipIndex = 0; shipIndex < SHIP_COUNT; shipIndex++) {
        ships[shipIndex]->print();
    }
}

int main(int argc, const char * argv[]) {
    const unsigned int SHIP_COUNT = 3;
    
    Ship* ships[SHIP_COUNT] = {
        new Ship("Alabama", "2020"),
        new CruiseShip("Georginian", "1976", 2000),
        new CargoShip("Alaskan", "2001", 500)
    };
    
    displayShips(ships, SHIP_COUNT);
    
    return 0;
}
