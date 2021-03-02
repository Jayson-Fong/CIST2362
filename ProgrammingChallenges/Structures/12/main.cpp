//
//  main.cpp
//  CourseGrade
//
//  Created by Jayson Fong on 2/13/21.
//

#include <iostream>
#include <iomanip>

const unsigned int getInt(const std::string);
const unsigned int getInt(const std::string, const unsigned int);
const std::string getName(const unsigned int);
const unsigned int getStudentCount();
const unsigned int getTestScoreCount();
void displayStudents(struct Student*, const unsigned int*);
void newlineDelimiter();
void generateScoreArrays(struct Student*, const unsigned int*, const unsigned int*);
const float getAverage(const unsigned int*, const unsigned int*);
void fillScores(struct Student*, const unsigned int*);
void processStudent(struct Student*, const unsigned int*, char (*)(const float));
void processStudents(struct Student*, const unsigned int*, const unsigned int*, char (*)(const float));
char standardGradeConverter(const float);
void process(void (*)());

/**
    Structures
 */

// Student Structure - Stores Student Test Information
struct Student {
    std::string Name;
    unsigned Idnum;
    unsigned int* Tests;
    unsigned int Average;
    char Grade;
};

/**
    Enumerated Lists
 */

// Grade Bounds -- Dictates What is an A, B, C, D, and F
enum GradeBounds {
    LOWER_A = 91,
    LOWER_B = 81,
    LOWER_C = 71,
    LOWER_D = 61
};

/**
    Input/Output
 */

const unsigned int getInt(const std::string messageText) {
    bool inputFailure;
    int num;
    
    do {
        std::cout << messageText << ": "; // Send message to client
        std::cin >> num; // Collect client input
        inputFailure = std::cin.fail() || num < 0; // Insure input is positive and was successful
        if (inputFailure) {
            std::cin.clear(); // Clear input if unsuccessful
            std::cin.ignore(INT8_MAX, '\n');
            std::cout << "Invalid Input: Please enter a positive integer." << std::endl;
        }
    } while (inputFailure);
    
    return num;
}

// Function for getting an int when a minimum is needed
const unsigned int getInt(const std::string messageText, const unsigned int min) {
    int num;
    bool inputFailure;
    
    do {
        num = getInt(messageText);
        inputFailure = num < min; // Check if input more than or equal to max.
        if (inputFailure) {
            std::cout << "Invalid Input: Please enter an integer of at least " << min << '.' << std::endl;
        }
    } while (inputFailure);
    
    return num;
}

const std::string getName(const unsigned int idNum) {
    std::string name;
    bool inputFailure;
    
    // Clear input because of previous cin
    std::cin.clear();
    std::cin.ignore(INT8_MAX, '\n');
    do {
        std::cout << "Student Name for ID #" << idNum << ": "; // Prompt text
        getline(std::cin, name); // Get a line
        inputFailure = std::cin.fail() || name.length() == 0;
        if (inputFailure) {
            std::cin.clear(); // Clear input on error
            std::cin.ignore(INT8_MAX, '\n');
            std::cout << "Please enter a valid name." << std::endl;
        }
    } while (inputFailure);
    
    return name;
}

// Prompts user for student count
const unsigned int getStudentCount() {
    return getInt("Student Count", 1);
}

// Prompts user for test score count
const unsigned int getTestScoreCount() {
    return getInt("Test Score Count", 1);
}

// Display students
void displayStudents(struct Student* students, const unsigned int* STUDENT_COUNT) {
    std::cout << "Student Test Summary (" << *STUDENT_COUNT << "):" << std::endl;
    // Runs through every student
    for (int studentIndex = 0; studentIndex < *STUDENT_COUNT; studentIndex++) {
        struct Student* studentPtr = students + studentIndex;
        std::cout << "\t" << std::setw(20) << std::left << (*studentPtr).Name << '(' << (*studentPtr).Idnum << "):" << std::endl; // Display student info
        std::cout << "\t\tAverage Grade: " << std::setprecision(5) << (*studentPtr).Average << "% (" << (*studentPtr).Grade << ')' << std::endl; // Display student grade & average
    }
}

void newlineDelimiter() {
    std::cout << std::endl;
}

/**
    Processing
 */

// Creates an array of unsigned intergers for test score storage
void generateScoreArrays(struct Student* students, const unsigned int* TEST_SCORE_COUNT, const unsigned int* STUDENT_COUNT) {
    for (int studentIndex = 0; studentIndex < *STUDENT_COUNT; studentIndex++) {
        (*(students + studentIndex)).Tests = new unsigned int[*TEST_SCORE_COUNT];
    }
}

// Calculates the average of an array of unsigned integers
const float getAverage(const unsigned int* scores, const unsigned int* TEST_SCORE_COUNT) {
    float scoreSum = 0;
    for (int scoreIndex = 0; scoreIndex < *TEST_SCORE_COUNT; scoreIndex++) {
        scoreSum += *(scores + scoreIndex);
    }
    
    return scoreSum / *TEST_SCORE_COUNT;
}

// Requests for scores from the client for 1 student
void fillScores(struct Student* student, const unsigned int* TEST_SCORE_COUNT) {
    for (int scoreIndex = 0; scoreIndex < *TEST_SCORE_COUNT; scoreIndex++) {
        *((*student).Tests + scoreIndex) = getInt("Test Score #" + std::to_string(scoreIndex + 1) + " for Student #" + std::to_string((*student).Idnum));
    }
}

// Process a single student's record
void processStudent(struct Student* student, const unsigned int* TEST_SCORE_COUNT, char (*gradeConverter)(const float)) {
    (*student).Idnum = getInt("Student ID Number"); // Get a student's Idnum
    (*student).Name = getName((*student).Idnum); // Get a student's name
    fillScores(student, TEST_SCORE_COUNT); // Get student's scores
    (*student).Average = getAverage((*student).Tests, TEST_SCORE_COUNT); // Calculate student's average
    (*student).Grade = gradeConverter((*student).Average); // Determine student's grade
}

// Process all students
void processStudents(struct Student* students, const unsigned int* TEST_SCORE_COUNT, const unsigned int* STUDENT_COUNT, char (*gradeConverter)(const float)) {
    for (int studentIndex = 0; studentIndex < *STUDENT_COUNT; studentIndex++) {
        processStudent(students + studentIndex, TEST_SCORE_COUNT, gradeConverter);
    }
}

// Determine a grade based on an average
char standardGradeConverter(const float grade) {
    if (grade >= LOWER_A) return 'A';
    else if (grade >= LOWER_B) return 'B';
    else if (grade >= LOWER_C) return 'C';
    else if (grade >= LOWER_D) return 'D';
    else return 'F';
}

void process(void (*delimService)()) {
    const unsigned int STUDENT_COUNT = getStudentCount();
    const unsigned int TEST_SCORE_COUNT = getTestScoreCount();
    
    delimService();
    struct Student* students = new Student[STUDENT_COUNT];
    generateScoreArrays(students, &TEST_SCORE_COUNT, &STUDENT_COUNT); // Dynamically allocates memory
    processStudents(students, &TEST_SCORE_COUNT, &STUDENT_COUNT, &standardGradeConverter); // Process students
    delimService();
    displayStudents(students, &STUDENT_COUNT); // Displays students
    delimService();
}

int main(int argc, const char * argv[]) {
    bool cont;
    
    do {
        process(&newlineDelimiter);
        cont = getInt("Would you like to continue?\n[1]: Yes\n[2]: No\nDecision") == 1; // Checks if the user would like to continue.
    } while (cont);
    
    return 0;
}
