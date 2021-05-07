//
//  main.cpp
//  TotalTemplate
//
//  Created by Jayson Fong on 3/21/21.
//

#include <iostream>

/**
    Exceptions
 */
class NegativeInputError {

public:
    
    const std::string explain() {
        return "Please enter a value of at least 0.";
    }
    
};

class ExcessiveFailureError {

public:
    
    const std::string explain() {
        return "Too many failed attempts.";
    }
    
};


/**
    Error Handling
 */
void displayError(const std::string error) {
    std::cout << error << std::endl;
}

/**
    Processing
 */
const unsigned int getInteger(const std::string message) {
    unsigned int userInput;
    bool fail;
    
    do {
        std::cout << message << ": ";
        std::cin >> userInput;
        
        fail = std::cin.fail();
        if (fail) {
            std::cout << "Invalid value entered. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        }
    } while(fail);
    
    return userInput;
}

bool continueProcessRequest() {
    unsigned int userInput;
    bool fail;
    
    do {
        std::cout << "[1] Continue" << std::endl;
        std::cout << "[2] Quit" << std::endl;
        std::cout << "Select Option: ";
        std::cin >> userInput;
        
        fail = std::cin.fail();
        if (fail) {
            std::cout << "Invalid value entered. Please try again and select an option." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        }
    } while(fail);
    
    return userInput == 1;
}

template <class T>
void accumulate(T &sum) {
    T userInput; // User Input
    bool fail;
    
    do {
        std::cout << "Enter Value: ";
        std::cin >> userInput;
        
        fail = std::cin.fail();
        if (fail) {
            std::cout << "Invalid value entered. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        }
    } while(fail);
    
    if (userInput < 0) {
        throw NegativeInputError();
    }
    
    sum += userInput;
}

template <class T>
T total(const T numValues) {
    T sum = 0; // Starting Value
    
    bool retry;
    unsigned short attempts;
    for (unsigned int counter = 0; counter < numValues; counter++) {
        retry = true;
        attempts = 0;
        do {
            try {
                accumulate(sum);
                retry = false;
            } catch (NegativeInputError &negativeInputError) {
                displayError(negativeInputError.explain());
                attempts++;
            }
        } while (retry == true && attempts < 3);
        if (retry == true) {
            throw ExcessiveFailureError();
        }
    }
    
    return sum;
}

// Required Because of Potential Overflow
unsigned int total(const char numValues) {
    char temp = 0; // Starting Value
    unsigned int sum = 0;
    
    bool retry;
    unsigned short attempts;
    for (unsigned int counter = 0; counter < numValues; counter++) {
        retry = true;
        attempts = 0;
        do {
            try {
                accumulate(temp);
                sum += temp;
                temp = 0;
                retry = false;
            } catch (NegativeInputError &negativeInputError) {
                displayError(negativeInputError.explain());
                attempts++;
            }
        } while (retry == true && attempts < 3);
        if (retry == true) {
            throw ExcessiveFailureError();
        }
    }
    
    return sum;
}

/**
    Processing
 */
template <class T>
void processor(const T numValues) {
    T sum = total(numValues);
    std::cout << "Result: " << sum << std::endl;
}

// Used for Conversion to an Integer
void processor(const char numValues) {
    unsigned int sum(total(numValues));
    std::cout << "Result: " << sum << std::endl;
}

void process() {
    int amount;
    bool error;
    do {
        amount = getInteger("Amount of Values");
        error = amount < 1;
        
        if (error) {
            std::cout << "Please enter an input count of at least 1." << std::endl;
        }
    } while (error);
    
    // Conversions
    // const unsigned int intSum = (int) amount; // Not Needed: Is Amount Type
    const double doubleSum = (double) amount;
    const char charSum = (char) amount;
    
    // Integers
    std::cout << std::endl << "Integer Accumulation" << std::endl;
    processor(amount);
    
    // Doubles
    std::cout << "Double Accumulation" << std::endl;
    processor(doubleSum);
    
    // Characters
    std::cout << "Character Accumulation" << std::endl;
    processor(charSum);
}

/**
    Main
 */
int main(int argc, const char * argv[]) {
    try {
        bool continueService;
        do {
            process();
            continueService = continueProcessRequest();
        } while (continueService);
    } catch (ExcessiveFailureError &excessiveFailureError) {
        displayError(excessiveFailureError.explain());
    }
    return 0;
}
