//
//  RandomNumberSet.h
//  RandomNumberSet
//
//  Created by Jayson Fong on 3/1/21.
//

#ifndef RandomNumberSet_h
#define RandomNumberSet_h

#include <time.h>
#include <stdlib.h>

class RandomNumberSet {
    
private:
        
    unsigned short numCount;
    unsigned short maxValue;
    unsigned short* randomIntegers;
    
    void _loadNumbers() {
        randomIntegers = new unsigned short[numCount];
        for (unsigned short valueIndex = 0b0; valueIndex < numCount; valueIndex++) {
            *(randomIntegers + valueIndex) = std::rand() % (maxValue + 0b1);
        }
    }
    
public:
    
    RandomNumberSet(const unsigned short count, const unsigned short maximum) {
        numCount = count;
        maxValue = maximum;
        std::srand((unsigned int) time(NULL));
    }
    
    void loadNumbers() {
        _loadNumbers();
    }
    
    const unsigned short* getRandomIntegers() {
        return randomIntegers;
    }
    
    const unsigned short getValueCount() {
        return numCount;
    }
    
    const unsigned short getMaxValue() {
        return maxValue;
    }
    
    const unsigned short getMinimum() {
        unsigned short minimum = *randomIntegers;
        for (unsigned short valueIndex = 0b1; valueIndex < numCount; valueIndex++) {
            if (*(randomIntegers + valueIndex) < minimum) {
                minimum = *(randomIntegers + valueIndex);
            }
        }
        return minimum;
    }
    
    const unsigned short getMaximum() {
        unsigned short maximum = *randomIntegers;
        for (unsigned short valueIndex = 0b1; valueIndex < numCount; valueIndex++) {
            if (*(randomIntegers + valueIndex) > maximum) {
                maximum = *(randomIntegers + valueIndex);
            }
        }
        return maximum;
    }
    
};

#endif /* RandomNumberSet_h */
