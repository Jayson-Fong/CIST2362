//
//  Database.cpp
//  PasswordService
//
//  Created by Jayson Fong on 4/29/21.
//

#include "Database.hpp"
#include <string>
#include "Password.hpp"

// Register a user in the database
void Database::registerUser(const std::string username, const std::string password) {
    // Make sure the username does not already exist
    if (this->getUser(username) != nullptr) {
        throw Database::RegisterError::EXISTS;
    }
    
    // Crate the new user
    Database::User* newUser = new User;
    newUser->username = username;
    newUser->passwordHash = Password::hash(password);
    newUser->passwordHistory = new Database::PasswordHistory;
    newUser->passwordHistory->passwordHash = newUser->passwordHash;
    
    // If the user table is empty, set the new one as the first
    if (this->head == nullptr) {
        this->head = newUser;
        this->tail = newUser;
        return;
    }
    
    // Configure the tail for the new user if one already exists
    this->tail->nextPtr = newUser;
    this->tail = newUser;
}

// Log a login attempt
void Database::logAttempt(const std::string username) {
    Database::User* user = this->getUser(username);
    if (user != nullptr) {
        ++user->attempts;
    }
}

// Clear attempts
void Database::clearAttempts(const std::string username) {
    Database::User* user = this->getUser(username);
    if (user != nullptr) {
        user->attempts = 0;
    }
}

// Change the password for a user
void Database::changePassword(const std::string username, const std::string newPassword) {
    // Get the user
    Database::User* activeUser = this->getUser(username);
    activeUser->passwordHash = Password::hash(newPassword);
    
    // Clear attempts
    activeUser->attempts = 0;
    
    // Create a new history entry
    PasswordHistory* historyEntry = new PasswordHistory;
    historyEntry->passwordHash = activeUser->passwordHash;
    
    // Append the history entry
    PasswordHistory* passwordHistoryPtr = activeUser->passwordHistory;
    while (passwordHistoryPtr->nextPtr != nullptr) {
        passwordHistoryPtr = passwordHistoryPtr->nextPtr;
    }
    // append the new password history
    passwordHistoryPtr->nextPtr = historyEntry;
}

// Gets a user's profile from the database
Database::User* Database::getUser(const std::string username) {
    Database::User* userPtr = this->head;
    // loop through until the user is found.
    while (userPtr != nullptr) {
        if (userPtr->username == username) return userPtr;
        userPtr = userPtr->nextPtr;
    }
    return nullptr;
}

// Checks if a user already exists in the database.
const bool Database::passwordUsed(const Database::User* user, const std::string password) {
    Database::PasswordHistory* historyNode = user->passwordHistory;
    const unsigned long passwordHash = Password::hash(password);
    unsigned int passwordIndex = 0;
    while (historyNode && passwordIndex < Database::HISTORIC_REJECT) {
        if (historyNode->passwordHash == passwordHash) return true;
        historyNode = historyNode->nextPtr;
        passwordIndex = passwordIndex + 1;
    }
    return false;
}

// Sets a new admin token
void Database::setAdminPassword(const std::string password) {
    this->adminHash = Password::hash(password);
}

// Verifies the admin token is correct
const bool Database::validAdmin(const std::string password) {
    return this->adminHash == Password::hash(password);
}

// Verifies that a user's login credentials is correct.
const bool Database::valid(const Database::User* user, const std::string password) {
    const unsigned long passwordHash = Password::hash(password);
    return user->passwordHash == passwordHash;
}

// Deconstructor
Database::~Database() {
    Database::User* nodePtr = head;
    Database::User* nextPtr;
    while (nodePtr->nextPtr) {
        // Delete password history
        Database::PasswordHistory* historyPtr = nodePtr->passwordHistory;
        Database::PasswordHistory* nextHistoryPtr;
        while (historyPtr->nextPtr) {
            nextHistoryPtr = historyPtr->nextPtr;
            delete historyPtr;
            historyPtr = nextHistoryPtr;
        }
        
        nextPtr = nodePtr->nextPtr;
        delete nodePtr;
        nodePtr = nextPtr;
    }
    delete nodePtr;
}
