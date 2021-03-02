//
//  main.cpp
//  WordCounter
//
//  Created by Jayson Fong on 1/25/21.
//  Created for Gwinnett Technical College.
//  CIST2362: C++ Programming II
//

#include <iostream>
#include <cctype>
#include <string>
#include <limits>
#include <cstring>
#include <string>
#include <limits>
#include <memory>

int getInt(const char*);
std::shared_ptr<char> getCString(const char*, const int, const int);
const bool isQuote(const char);
bool isSeparator(const char);
int countWords(const char*, const char, const int);
void printLine(const int);
int countWords(const std::string, const char, const int);
void displayResult(const int*);
void process();
void outMessage();
void runWrapper(void (*)(), const int n);


int getInt(const char* messageText) {
    // Ensures the Input is Valid
    bool inputFailure;
    // Stores the provided integer.
    int num;
    
    // Run until a valid integer is provided.
    do {
        // Prompts the client.
        std::cout << messageText << ": ";
        // Requests input.
        std::cin >> num;
        // Checks if the input is bad.
        inputFailure = std::cin.fail();
        if (inputFailure) {
            // Clears the input.
            std::cin.clear();
            std::cin.ignore(INT8_MAX, '\n');
            std::cout << "Invalid Input: Please enter an integer." << std::endl;
        }
    } while (inputFailure);
    
    // Return the resulting value.
    return num;
}

std::shared_ptr<char> getCString(const char* messageText, const int MIN_LENGTH = 0, const int MAX_LENGTH = 1000) {
    // Ensures the Input is Valid
    bool inputFailure;
    // Determines size
    // 1 extra char for the null terminator.
    // 1 extra char for length checking.
    const int SIZE = MAX_LENGTH + 2;
    // Stores the provided string. Static so the pointer is valid.
    std::shared_ptr<char> inputText(new char[SIZE], std::default_delete<char[]>());
    
    // Run until a valid string is provided.
    do {
        // Prompts the client
        std::cout << messageText << ": ";
        // Gets the line up to the newline.
        std::cin.getline(inputText.get(), SIZE);
        // Checks if the input is valid
        const unsigned long length = std::strlen(inputText.get());
        inputFailure = std::cin.fail() || length < MIN_LENGTH || (MAX_LENGTH > 0 && length > MAX_LENGTH);
        if (inputFailure) {
            std::cin.clear();
            if (length < MIN_LENGTH) {
                std::cout << "Input Error: Please enter a string of more than " << MIN_LENGTH << " characters." << std::endl;
            } else if (length > MAX_LENGTH) {
                std::cout << "Input Error: Please enter a string of less than " << MAX_LENGTH << " characters." << std::endl;
                // Gets rid of the excess characters in the stream.
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                std::cout << "Input Error: There was a problem processing your input. Please try again." << std::endl;
            }
        }
    } while (inputFailure);
    
    return inputText;
}

const bool isQuote(const char input) {
    return input == '\'';
}

// Checks if the input is NOT a quote AND is a blank/space/punctuation.
bool isSeparator(const char input) {
    return !isQuote(input) && (isblank(input) || isspace(input) || ispunct(input));
}

// TERM_CHAR marks the end of the sequence of characters.
// READ_LIMIT is in case the TERM_CHAR is never met -- maximum index.
int countWords(const char* chars, const char TERM_CHAR = '\0', const int READ_LIMIT = 1000) {
    // Initialize to true to ignore starting spaces.
    bool lastSpace = true;
    // Increments if a word is found when the last is a space.
    int words = 0;
    
    int index = 0;
    // Run as long as the terminator character and read limit is not met.
    while(*(chars + index) != TERM_CHAR && index < READ_LIMIT) {
        if (isSeparator(*(chars + index)) || (lastSpace && isQuote(*(chars + index)))) {
            lastSpace = true;
        } else if ((isalnum(*(chars + index)) || isQuote(*(chars + index))) && lastSpace) {
            lastSpace = false;
            words++;
        }
        index++;
    }
        
    return words;
}

void printLine(const int n) {
    std::string line(n, '=');
    std::cout << line << std::endl;
}

int countWords(const std::string str, const char TERM_CHAR = '\0', const int READ_LIMIT = 1000) {
    return countWords(str.c_str(),  TERM_CHAR, READ_LIMIT);
}

void displayResult(const int* count) {
    std::cout << "The string contained " << *count << " words." << std::endl;
}

void process() {
    // Generates the prompt text.
    const std::string promptText = "Enter Phrase";
    const char* promptChars = promptText.c_str();
    std::shared_ptr<char> chars;
    // Gets the string from the client.
    // Minimum Length: 30 Characters
    // Maximum Length: 1000 Characters
    chars = getCString(promptChars, 30, 1000);
    // Calculates the word count
    const int wordCount = countWords(chars.get());
    // Displays the result.
    displayResult(&wordCount);
}

void outMessage() {
    std::cout << "Thank you for using the WordCounter." << std::endl;
}

void runWrapper(void (*processor)(), const int n = 50) {
    printLine(n);
    processor();
    printLine(n);
}

int main(int argc, const char * argv[]) {
    // Creates a C-String of the prompt text.
    const std::string promptText = "Continue? Enter [0] to Quit or Enter [1] to Continue";
    const char* promptChars = promptText.c_str();
    
    // Keeps track of if the client wishes to continue processing or not.
    bool cont;
    // Runs until the client decides to exit.
    do {
        runWrapper(&process);
        // Checks if the client wishes to exit.
        cont = getInt(promptChars) == 1;
        if (cont) {
            std::cout << "Continuing..." << std::endl;
        }
        std::cin.ignore();
    } while (cont);
    
    runWrapper(&outMessage);
    
    return 0;
}
