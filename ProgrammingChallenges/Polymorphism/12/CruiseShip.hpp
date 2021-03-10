//
//  CruiseShip.hpp
//  Shipping
//
//  Created by Jayson Fong on 3/7/21.
//

#ifndef CruiseShip_hpp
#define CruiseShip_hpp

#include <stdio.h>
#include <string>
#include "Ship.hpp"

class CruiseShip : public Ship {
    
private:
    
    unsigned int maxPassengers;
    
public:
    
    CruiseShip(const std::string, const std::string, const unsigned int);
    
    const unsigned int getMaxPassengers();
    
    void setMaxPassengers(const unsigned int);
    
    virtual void print();
    
};

#endif /* CruiseShip_hpp */
