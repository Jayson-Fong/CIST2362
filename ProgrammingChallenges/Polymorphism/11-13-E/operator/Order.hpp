//
//  Order.hpp
//  DrinkMachineSimulator
//
//  Created by Jayson Fong on 3/8/21.
//

#ifndef Order_hpp
#define Order_hpp

#include <stdio.h>
#include <string>
#include "Item.hpp"

class Order {
    
private:
    
    Item* orderItem;
    double &revenue;
    void displayItem();
    const double getPayment();
    void showChange(const double);
    void outOfStock();
    void abort();
    void dispenseNotify();
    
public:
    
    Order(Item*, double &);
    void process();
    
};

#endif /* Order_hpp */
