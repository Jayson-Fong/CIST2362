//
//  Application.hpp
//  Application Service
//
//  A simple way to keep on running.
//
//  Created by Jayson Fong on 3/27/21.
//

#ifndef Application_hpp
#define Application_hpp

#include <stdio.h>
#include <string>

class Application {
    
private:
    
    // Function to Run in Loop
    void (*service)();
    // Stores if The App Should Continue
    bool active;
    // Application Name
    std::string name;
    
    // Asks client if they wish to continue
    bool ask();
    
public:
    
    // Constructor
    Application(void (*serviceFunc)()) {
        this->service = serviceFunc;
        this->name = "Application";
    }
    
    // Constructor
    Application(void (*serviceFunc)(), std::string appName) {
        this->service = serviceFunc;
        this->name = appName;
    }
    
    // Run the Service Once
    void run();
    // Start the Service Loop
    void start();
    // End the Service Loop
    void stop();
    
};

#endif /* Application_hpp */
