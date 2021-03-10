//
//  CargoShip.hpp
//  Shipping
//
//  Created by Jayson Fong on 3/7/21.
//

#ifndef CargoShip_hpp
#define CargoShip_hpp

#include <stdio.h>
#include <string>
#include "Ship.hpp"

class CargoShip : public Ship {
  
private:
    
    unsigned int tonnage;
    
public:
    
    CargoShip(const std::string, const std::string, const unsigned int);
    
    const unsigned int getTonnage();
    
    void setTonnage(const unsigned int);
    
    virtual void print();
    
};

#endif /* CargoShip_hpp */
