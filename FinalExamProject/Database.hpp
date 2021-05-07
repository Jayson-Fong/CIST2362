//
//  Database.hpp
//  PasswordService
//
//  Created by Jayson Fong on 4/29/21.
//

#ifndef Database_hpp
#define Database_hpp

#include <stdio.h>
#include <string>
#include "Password.hpp"

class Database {
  
private:
    
    enum RegisterError {
        EXISTS
    };
    
    struct PasswordHistory {
        unsigned long passwordHash;
        struct PasswordHistory* nextPtr = nullptr;
    };
    
    struct User {
        // User Details
        std::string username;
        unsigned long passwordHash;
        // Structural
        struct Database::User* nextPtr = nullptr;
        // Security
        struct Database::PasswordHistory* passwordHistory;
        unsigned int attempts = 0;
    };
    
    User* head = nullptr;
    User* tail = nullptr;
    
    unsigned long adminHash;
        
public:
    
    static const unsigned int HISTORIC_REJECT = 4;
    
    // Register a Useer
    void registerUser(const std::string, const std::string);

    // Log a login attempt
    void logAttempt(const std::string);
    
    // Clear attempts
    void clearAttempts(const std::string);
    
    // Change a user's password
    void changePassword(const std::string, const std::string);
    
    // Get a user from the database
    Database::User* getUser(const std::string);
    
    // Checks if a password was used recently based on HISTORIC_REJECT
    const bool passwordUsed(const Database::User*, const std::string);
    
    // Sets the admin token
    void setAdminPassword(const std::string);
    
    // Verifies the admin token
    const bool validAdmin(const std::string);
        
    // Verifies login credentials
    static const bool valid(const Database::User*, const std::string);
    
    // Destructor
    ~Database();
    
};

#endif /* Database_hpp */
