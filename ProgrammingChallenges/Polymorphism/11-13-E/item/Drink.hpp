//
//  Drink.hpp
//  DrinkMachineSimulator
//
//  Created by Jayson Fong on 3/8/21.
//

#ifndef Drink_hpp
#define Drink_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "Item.hpp"

class Drink : public Item {
    
    using Item::Item;
    
public:
    
    virtual const std::string getDescription() const;
    
    friend std::ostream &operator <<(std::ostream &out, const Drink &item) {
        out << item.getDescription();
        return out;
    }
    
};

#endif /* Drink_hpp */
