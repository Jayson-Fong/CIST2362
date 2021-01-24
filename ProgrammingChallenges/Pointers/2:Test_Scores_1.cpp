//
//  TestScores
//
//  Created by Jayson Fong on 1/23/21.
//
//  Created for:
//  CIST2362: C++ Programming II
//  Gwinnett Technical College
//

#include <iostream>
#include <charconv>
#include <string>
#include <iomanip>

using namespace std;

void getInt(const string*, int*);
void getInt(const string*, const int*, int*);
void fillTestScores(int*, const int*);
void sortAscending(int*, const int*);
void getAverage(int*, const int*, double*);
void displayResults(int*, const int*);
void testScoresService();


void getInt(const string* messageText, int* num) {
    // Ensures the Input is Valid
    bool inputFailure;
    bool* inputFailurePtr = &inputFailure;
    
    // Run until a valid integer larger than min is provided.
    do {
        cout << *messageText << ": ";
        cin >> *num;
        // Verifies the input is valid.
        *inputFailurePtr = cin.fail();
        if (*inputFailurePtr) {
            // Clear the input for a new value to be inputted.
            cin.clear();
            cin.ignore(INT8_MAX, '\n');
            // Send an error message on failure.
            cout << "Invalid Input: Please enter an integer." << endl;
        }
    } while (*inputFailurePtr);
}

void getInt(const string* messageText, const int* min, int* num) {
    // Function Ptrs
    void (*func1)(const string*, int*) = &getInt;
    // Ensures the Input is Valid
    bool inputFailure;
    bool* inputFailurePtr = &inputFailure;
    
    // Runs until the minimum condition is met.
    do {
        func1(messageText, num);
        *inputFailurePtr = *num < *min;
        if (*inputFailurePtr) {
            cout << "Invalid Input: Please enter an integer that is at least " << *min << "." << endl;
        }
    } while (*inputFailurePtr);
}

void fillTestScores(int* scores, const int* SCORE_COUNT) {
    // Fill Scores Array
    int minScore = 0;
    int* minScorePtr = &minScore;
    for (int i = 0; i < *SCORE_COUNT; i++) {
        string messageText = "Test Score #" + to_string(i + 1);
        // Put Score into Array
        getInt(&messageText, minScorePtr, scores + i);
    }
}

void sortAscending(int* scores, const int* SCORE_COUNT) {
    // Run Sort for Each Index
    for (int i = 0; i < *SCORE_COUNT - 1; i++) {
        int minIndex = i;
        // Find Minimum Starting from i
        for (int j = i; j < *SCORE_COUNT; j++) {
            // If j's value is larger than the current minimum's, set j as the new min.
            if (*(scores + j) < *(scores + minIndex)) {
                minIndex = j;
            }
        }
        // Do Swap
        int temp = *(scores + i);
        *(scores + i) = *(scores + minIndex);
        *(scores + minIndex) = temp;
    }
}

void getAverage(int* scores, const int* SCORE_COUNT, double* average) {
    int sum = 0;
    int* sumPtr = &sum;
    // Add All Values to Sum
    for (int i = 0; i < *SCORE_COUNT; i++) {
        *sumPtr += *(scores + i);
    }
    // Return Average
    *average = (double) *sumPtr / *SCORE_COUNT;
}

void displayResults(int* scores, const int* SCORE_COUNT) {
    // Function Ptrs
    void (*func1)(int*, const int*, double*) = &getAverage;
    // Calculate Average Score
    double average;
    func1(scores, SCORE_COUNT, &average);
    cout << "Scores:" << endl;
    // Display Scores
    for (int i = 0; i < *SCORE_COUNT; i++) {
        cout << "\t" << *(scores + i) << '%' << endl;
    }
    // Display Average Score
    cout << "Average Score: " << fixed << setprecision(2) << average << '%' << endl;
}

void testScoresService() {
    // Function Ptrs
    void (*func1)(const string*, const int*, int*) = &getInt;
    void (*func2)(int*, const int*) = &fillTestScores;
    void (*func3)(int*, const int*) = &sortAscending;
    void (*func4)(int*, const int*) = &displayResults;
    // Get Score Count
    int SCORE_COUNT;
    int min = 1;
    string messageText = "Test Score Amount to Enter";
    func1(&messageText, &min, &SCORE_COUNT);
    // Create Array
    int scores[SCORE_COUNT];
    // Get Scores
    func2(scores, &SCORE_COUNT);
    // Sort Scores in Ascending Order
    func3(scores, &SCORE_COUNT);
    // Display Results
    func4(scores, &SCORE_COUNT);
}

int main(int argc, const char * argv[]) {
    // Function Ptrs
    void (*func1)() = &testScoresService;
    void (*func2)(const string*, int*) = &getInt;
    // Run program until the user chooses to exit.
    int exit;
    string messageText = "Enter [0] to Exit or [1] to Continue";
    do {
        // Run Test Score Service
        func1();
        // Ask if the Client Would Like to Continue
        func2(&messageText, &exit);
    } while (exit == 1);
    
    return 0;
}
