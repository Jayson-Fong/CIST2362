//
//  NumberFormat.cpp
//  DrinkMachineSimulator
//
//  Created by Jayson Fong on 3/8/21.
//

#include <sstream>
#include <iomanip>
#include "NumberFormat.hpp"

// Formats numbers to have only 2 decimal places and turns it into American currency format.
const std::string NumberFormat::moneyFormat(const double dollars) {
    std::ostringstream costStream;
    costStream << std::fixed << std::setprecision(2) << dollars;
    std::string moneyFormat = '$' + costStream.str();
    return moneyFormat;
}
