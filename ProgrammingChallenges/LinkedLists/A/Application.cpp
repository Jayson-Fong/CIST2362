//
//  Application.cpp
//  Application Service
//
//  A simple way to keep on running.
//  https://gist.github.com/Jayson-Fong/9337fb32ba19f491a96df3edf5862efa
//
//  Created by Jayson Fong on 3/27/21.
//

#include "Application.hpp"
#include <iostream>
#include <limits>

bool Application::ask() {
    char input;
    bool failure;
    
    // Create a separator of 64 equal signs
    std::string separator(64, '=');

    // Print the separator
    std::cout << std::endl << separator << std::endl;
    do {
        // Ask the client if they want to continue
        std::cout << "Would you like to continue running " << this->name << '?' << std::endl;
        std::cout << "Enter `y` to continue or `n` to exit this program." << std::endl;
        std::cout << "Decision [y/n]: ";
        
        // Fetch the input
        std::cin >> input;
        if (std::cin.fail()) {
            // If there was a problem getting the response...
            std::cout << std::endl << "Sorry, we could not understand your response." << std::endl << std::endl;
            failure = true;
        } else {
            // Convert to lowercase
            input = tolower(input);
            if (input != 'y' && input != 'n') {
                // If the input is invalid
                std::cout << std::endl << "We could not understand your input. Please enter either `y` or `n`." << std::endl << std::endl;
                failure = true;
            } else {
                // All good!
                failure = false;
            }
        }
        
        if (failure) {
            // If failure, clear input.
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        }
    } while (failure);
    
    // Print end separator
    std::cout << separator << std::endl << std::endl;
    
    return input == 'y';
}

// Run the service just once
void Application::run() {
    this->service();
}

// Start a loop
void Application::start() {
    this->active = true;
    bool clientContinue;
    do {
        // Execute once
        this->service();
        // If we have not asked it to stop
        if (active) {
            clientContinue = this->ask();
        } else {
            // Just in case we ask it to stop
            std::cout << "Service Terminated" << std::endl;
            clientContinue = false;
        }
    } while (clientContinue);
}

// Kindly ask for the service to stop
void Application::stop() {
    this->active = false;
}
