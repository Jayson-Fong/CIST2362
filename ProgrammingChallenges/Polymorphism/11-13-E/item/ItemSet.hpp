//
//  ItemSet.hpp
//  DrinkMachineSimulator
//
//  Created by Jayson Fong on 3/8/21.
//

#ifndef ItemSet_hpp
#define ItemSet_hpp

#include <stdio.h>
#include "Item.hpp"

struct ItemSet {
    unsigned short count;
    Item** items;
};

#endif /* ItemSet_hpp */
