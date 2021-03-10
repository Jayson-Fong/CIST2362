//
//  Ship.hpp
//  Shipping
//
//  Created by Jayson Fong on 3/7/21.
//

#ifndef Ship_hpp
#define Ship_hpp

#include <stdio.h>
#include <string>

class Ship {
  
protected:
    
    std::string name;
    
    std::string yearBuilt;
    
public:
    
    Ship(const std::string, const std::string);
    
    const std::string getName();
    
    const std::string getYearBuilt();
    
    void setName(const std::string);
    
    void setYearBuilt(const std::string);
    
    virtual void print();
    

};

#endif /* Ship_hpp */
