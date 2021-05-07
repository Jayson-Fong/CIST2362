//
//  main.cpp
//  PasswordService
//
//  Created by Jayson Fong on 4/29/21.
//

#include <iostream>
#include "Decision.hpp"
#include "Database.hpp"
#include "Input.hpp"
#include "Password.hpp"

// Create the default users
void createDefaults(Database* database) {
    // Admin
    database->setAdminPassword("#R*RIdRobR2-wi9rE&o&");
    // User 01: dhammond
    database->registerUser("dhammond", "brepHagUhU#&1rugIdRi");
    database->changePassword("dhammond", "3$8Q&PrifRAkuFIjO8es");
    database->changePassword("dhammond", "NiXet?$p=fr+MO_P5763");
    database->changePassword("dhammond", "C@lv4DAch40ufe0USt?d");
    // User 02: adao
    database->registerUser("adao", "DejLphiT-lX#5?xU7teb");
    database->changePassword("adao", "sPlka8oy$tre2O3Raqom");
    database->changePassword("adao", "c?@8ixLd4pRawr+92!#a");
    database->changePassword("adao", "t+Ofa+ojospUcowo20Sw");
    // User 03: esmith
    database->registerUser("esmith", "9lFrUsP939xE!AwrE3E#");
    database->changePassword("esmith", "_UcHaD=a?e@pemichi2$");
    database->changePassword("esmith", "swob_8pAsE0RIwruxoG$");
    database->changePassword("esmith", "ZuB*9tHutEf6ofoV!Ko-");
    // User 04: qshawn
    database->registerUser("qshawn", "v7zidesWive=r#dro#p-");
    database->changePassword("qshawn", "CratH$haC0Pr+zoy-bi5");
    database->changePassword("qshawn", "&2sTLvEjAgAxoTefr9!?");
    database->changePassword("qshawn", "J6joTHL&abru=riroq72");
    // User 05: dtrump
    database->registerUser("dtrump", "TRa0Ipag&93sLfLkO4@i");
    database->changePassword("dtrump", "vu&#07AX7tLYLtR7s9aD");
    database->changePassword("dtrump", "daw3*rubr!sPu@*t$ot9");
    database->changePassword("dtrump", "phEswithlh0st&5Ta*i0");
    // User 06: jbiden
    database->registerUser("jbiden", "r$5o0wEstuFlDaquCh6f");
    database->changePassword("jbiden", "narapup7_ha7*rA?@i+2");
    database->changePassword("jbiden", "sw$ra@r6#aprecr2zLho");
    database->changePassword("jbiden", "yUH*2oT+#H20iD@?iF21");
    // User 07: ycampbell
    database->registerUser("ycampbell", "Zu=*Oc1eci!rlsw93Ebi");
    database->changePassword("ycampbell", "g*ku?rlslw6Efr@6imlc");
    database->changePassword("ycampbell", "ph?$lPha1*xOp3aB9ewa");
    database->changePassword("ycampbell", "beyOq$*1EPach$b=l?po");
    // User 08: rmatt
    database->registerUser("rmatt", "chLdL=A8&-r$3Obot4t@");
    database->changePassword("rmatt", "rLgl7688S-lTE0REwIc-");
    database->changePassword("rmatt", "P1epha=2pRa!oNUb&UnL");
    database->changePassword("rmatt", "XUw3i0wahl*l==pRU+Lt");
    // User 09: owashington
    database->registerUser("owashington", "pi_1ASwUhIk+s$#7_iWl");
    database->changePassword("owashington", "Dr96R6befr2tRODRi@uC");
    database->changePassword("owashington", "tHO_rl+_e85neR#YI21_");
    database->changePassword("owashington", "XO@r2P3brLCHuyidlCAf");
    // User 10: glink
    database->registerUser("glink", "1-wlweF_bR6DR?THu9L2");
    database->changePassword("glink", "dRop@s@$xlT2U6l1O1l1");
    database->changePassword("glink", "dath$t+LpHu#EsPOj8*5");
    database->changePassword("glink", "yuK-SPeSW--r$#eQlcH4");
}

// Show the password type notification.
void displayPasswordType(Password::Classification classification) {
    switch(classification) {
        case Password::Classification::WEAK:
            std::cout << "Your password is weak." << std::endl;
            break;
        case Password::Classification::STRONG:
            std::cout << "Your password is strong." << std::endl;
            break;
        case Password::Classification::VERY_SECURE:
            std::cout << "Your password is very secure." << std::endl;
            break;
        default:
            throw std::logic_error("Unknown Password Classification");
    }
}

// Stores login status.
void userCredential(std::string &username, bool stateChange = false) {
    // "" is logged out
    static std::string loggedInUsername = "";
    
    // If login/logout, replace existing.
    if (stateChange) {
        loggedInUsername = username;
        return;
    }
    
    // Set the input param to the logged in username.
    username = loggedInUsername;
}

// Returns the user's username
std::string getUsername() {
    std::string username;
    userCredential(username);
    return username;
}

// Initiate the login process
void login(Database* database) {
    // Get the existing login
    std::string credential;
    userCredential(credential);
    // If already logged in
    if (credential != "") {
        std::cout << "You are already logged in, " << credential << '.' << std::endl;
        return;
    }
    
    // Get login credentials
    std::string username = Input::getString("Username");
    const std::string password = Input::getString("Password");
    
    // Get the user
    auto* user = database->getUser(username);
    
    // Lock out
    if (user != nullptr && user->attempts > 3) {
        std::cout << "This account is currently locked out. Please reset your password." << std::endl;
        return;
    }
    
    // If the username is invalid or the username/password combination is invalid
    if (user == nullptr || !Database::valid(user, password)) {
        std::cout << "Invalid username or password provided. Please try again or reset your password." << std::endl;
        std::cout << "WARNING: Too many attempts will lock out your account." << std::endl;
        database->logAttempt(username);
        return;
    }
    
    // Show welcome message
    std::cout << "Welcome, " << username << "!" << std::endl;
    // Save login
    userCredential(username, true);
    // Clear login attempts counter
    database->clearAttempts(username);
}

// Log the user out
void logout(const Database* database) {
    // Get existing login
    std::string credential;
    userCredential(credential);
    
    // If not logged in
    if (credential == "") {
        std::cout << "You are currently not logged in." << std::endl;
        return;
    }
    
    // Set logged out
    credential = "";
    userCredential(credential, true);
    std::cout << "Successfully logged out." << std::endl;
}

// Secured area requiring login
void secureArea() {
    std::string credential;
    userCredential(credential);
    
    if (credential == "") {
        std::cout << "Unauthorized." << std::endl;
        return;
    }
    
    std::cout << "Hello " << credential << ", welcome to your secure portal." << std::endl;
    std::cout << "You currently do not have any invoices due. Check back later." << std::endl;
}

// Displays password criteria
void displayPasswordCriteria() {
    std::cout << std::endl;
    std::cout << "Criteria \tStrong\tVery Secure" << std::endl;
    std::cout << "Length   \t6\t\t8" << std::endl;
    std::cout << "Numbers  \t2\t\t2" << std::endl;
    std::cout << "Specials \t1\t\t2" << std::endl;
    std::cout << "Uppercase\t1\t\t1" << std::endl;
    std::cout << "Lowercase\t1\t\t1" << std::endl;
    std::cout << "Your password may be up to 45 characters." << std::endl;
    std::cout << "[Passwords Must be At Strong]" << std::endl;
    std::cout << std::endl;
}

// Displays the details of a password
void displayPasswordDetails(const Characterizer::CharType* charType) {
    std::cout << std::endl;
    std::cout << "Your Password Details" << std::endl;
    std::cout << "Length:   \t" << charType->length << std::endl;
    std::cout << "Numbers:  \t" << charType->numbers << std::endl;
    std::cout << "Specials: \t" << charType->special << std::endl;
    std::cout << "Uppercase:\t" << charType->uppercase << std::endl;
    std::cout << "Lowercase:\t" << charType->lowercase << std::endl;
    std::cout << std::endl;
}

// Do the password reset process
void passwordResetProcess(Database* database, const std::string username) {
    displayPasswordCriteria();
    // Get passwords
    std::string newPassword = Input::getString("New Password");
    const std::string newPasswordConfirm = Input::getString("Confirm New Password");
        
    // If passwords do not match
    if (newPassword != newPasswordConfirm) {
        std::cout << "The passwords you entered do not match. Please try again." << std::endl;
        return passwordResetProcess(database, username);
    }
    
    // If password is too long
    if (newPasswordConfirm.length() > 45) {
        std::cout << "Your password is too long. Please enter a maximum of 45 characters." << std::endl;
        return passwordResetProcess(database, username);
    }
    
    // Make Lowercase Variants
    std::string usernameLower(username);
    std::transform(newPassword.begin(), newPassword.end(), newPassword.begin(), [](unsigned char c){ return std::tolower(c); });
    std::transform(usernameLower.begin(), usernameLower.end(), usernameLower.begin(), [](unsigned char c){ return std::tolower(c); });
    // If the password is the same as the username
    if (newPassword == username) {
        std::cout << "Your password cannot match your username. Please try again." << std::endl;
        return passwordResetProcess(database, username);
    }
    
    // Get password type and character type summary
    const Password::PasswordDetails* details = Password::getDetails(newPasswordConfirm);
    // Show what kind of password it is (weak/strong/very secure)
    displayPasswordType(details->classification);
    // Displays the character makeup of the password
    displayPasswordDetails(details->detail);
    // Check if password is weak
    if (details->classification == Password::Classification::WEAK) {
        std::cout << "Please enter a more secure password." << std::endl;
        return passwordResetProcess(database, username);
    }
    
    // Check if password was previously used
    const auto* user = database->getUser(username);
    if (database->passwordUsed(user, newPasswordConfirm)) {
        std::cout << "Please enter a new password. You used that password too recently." << std::endl;
        return passwordResetProcess(database, username);
    }
    
    // Execute password change.
    database->changePassword(username, newPasswordConfirm);
    std::cout << "Your password is set." << std::endl;
}

// Password reset verification
void reset(Database* database, const bool bypassToken = false, std::string username = "", const bool verifyExisting = false) {
    // If the username is not already known, ask for it.
    if (username == "") {
        username = Input::getString("Account Username");
        // If the username does not exist.
        if (database->getUser(username) == nullptr) {
            std::cout << "Sorry, the requested user could not be found. Please try again or contact customer support." << std::endl;
            return;
        }
    }
    
    // If we have not already verified they can reset.
    if (!bypassToken) {
        std::cout << "Please enter your secure password reset token." << std::endl;
        std::string token = Input::getString("Secure Token");
    
        // If the token is correct.
        if (!database->validAdmin(token)) {
            std::cout << "Invalid secure password reset token. Please try again or contact customer support." << std::endl;
            return;
        }
    
        std::cout << "Secure token accepted. You are now ready to reset your password." << std::endl;
    }
    
    // Verify existing password
    if (verifyExisting) {
        const std::string existingPassword = Input::getString("Current Password");
        const auto* user = database->getUser(username);
        if (!database->valid(user, existingPassword)) {
            std::cout << "Your existing password is invalid. Please try again or contact customer support." << std::endl;
            return;
        }
    }
    
    // Complete the password processing phase.
    passwordResetProcess(database, username);
}

// Display information.
void info() {
    std::cout << "Welcome to the TNT login service. In the TNT portal, access your secure account information and pay invoices." << std::endl;
    std::cout << "If you have any issues, please contact your account representative." << std::endl;
    std::cout << "Copyright (c) 2021 Jayson Fong" << std::endl;
}

// Display welcome message.
void welcomeMessage() {
    std::cout << "Welcome to the TNT login service." << std::endl;
}

// Used for pathway taking
void decision(Database* database) {
    // Logged in
    static Decision* decisionKnown = nullptr;
    // Logged out
    static Decision* decisionUnknown = nullptr;
    
    // Initialize
    if (decisionKnown == nullptr) {
        // Logged In
        decisionKnown = new Decision;
        decisionKnown->appendNode("Read Messages"); // Option 1
        decisionKnown->appendNode("Change Password"); // Option 2
        decisionKnown->appendNode("Logout"); // Option 3
        // Logged Out
        decisionUnknown = new Decision;
        decisionUnknown->appendNode("Login"); // Option 1
        decisionUnknown->appendNode("Reset Password"); // Option 2
        decisionUnknown->appendNode("System Info"); // Option 3
        decisionUnknown->appendNode("Exit"); // Option 4
    }
    
    // Check login status
    std::string credential;
    userCredential(credential);
    
    // If logged out
    if (credential == "") {
        switch(decisionUnknown->choose()) {
            case 1:     login(database); break;
            case 2:     reset(database); break;
            case 3:     info(); break;
            case 4:     exit(0); break;
            default:    throw std::logic_error("Broken Choice Pipeline");
        }
        return;
    }
    
    // If logged in
    switch(decisionKnown->choose()) {
        case 1: secureArea(); break;
        case 2: reset(database, true, getUsername(), true); break;
        case 3: logout(database); break;
        default: throw std::logic_error("Broken Choice Pipeline");
    }
}

// store the database in a var and process
void prepare() {
    static Database* database = new Database;
    
    static bool generated = false;
    
    if (generated == false) {
        createDefaults(database);
        generated = true;
    }
    
    decision(database);
}

int main(int argc, const char * argv[]) {
    welcomeMessage();
    // loop the process forever until the user decides to exit in the decision process.
    do {
        prepare();
    } while (true);
    
    return 0;
}
