//
//  Drink.cpp
//  DrinkMachineSimulator
//
//  Created by Jayson Fong on 3/8/21.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Drink.hpp"
#include "NumberFormat.hpp"

const std::string Drink::getDescription() const {
    return "[Drink] " + getName() + ' ' + NumberFormat::moneyFormat(getCost());
}
