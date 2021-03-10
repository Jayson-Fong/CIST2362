//
//  Item.hpp
//  DrinkMachineSimulator
//
//  Created by Jayson Fong on 3/8/21.
//

#ifndef Item_hpp
#define Item_hpp

#include <stdio.h>
#include <string>

class Item {
    
private:
    
    std::string name;
    double cost;
    unsigned int stock;
    
public:
    
    Item(const std::string, const double, const unsigned int);
    
    /**
            Accessors
     */
    const std::string getName() const;
    const double getCost() const;
    const unsigned int getStock() const;
    
    /**
            Modifiers
     */
    void setName(const std::string);
    void setCost(const double);
    void setStock(const unsigned int);
    
    /**
            Stock Management
     */
    const bool dispense(const unsigned int);
    void restock(const unsigned int);
    
    /**
            Display
     */
    virtual const std::string getDescription() const = 0;
    
    /**
            Operators
     */
    friend std::ostream &operator <<(std::ostream &out, const Item &item) {
        out << item.getDescription();
        return out;
    }
    
};

#endif /* Item_hpp */
