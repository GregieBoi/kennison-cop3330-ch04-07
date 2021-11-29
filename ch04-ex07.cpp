/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 McGreggor Kennison
 */

#include "std_lib_facilities.h"

// initialize numbersString vector
vector<string> numbersString;


// fills numbersString vector with all possible valid input
void fillNumbers() {

    // push back each string to vector
    numbersString.push_back("zero");
    numbersString.push_back("one");
	numbersString.push_back("two");
	numbersString.push_back("three");
	numbersString.push_back("four");
	numbersString.push_back("five");
	numbersString.push_back("six");
	numbersString.push_back("seven");
	numbersString.push_back("eight");
	numbersString.push_back("nine");

}

// checks input and returns integer
int getNumber() {

    // initizialize and set variables notInRange and value
    const int notInRange = 10;
    int value = notInRange;

    // checks if input is in int form and returns if true
    if (cin >> value) {
        
        // check if input is in valid range if true return value if not throw error
        if (value < 10 && value >= 0)
            return value;
        else 
            error("value not in single digits: ", value);

    }

    // reset value to notInRange
    value = notInRange;

    // clear so that new read can be made
    cin.clear();

    // initialize value string and read input to it
    string valueString;
    cin >> valueString;

    // for size of numbersString vector
    for (int i = 0; i < 10; i++) {

        // checks if valueString equals string at i and if true it sets value to i
        if (numbersString[i] == valueString)
            value = i;

    }

    // checks if value still equals notInRange and if true throws error
    if (value == notInRange)
        error("Invalid string: ", valueString);

    // returns value
    return value;

}

int main() {

    // call fillNumbers
    fillNumbers();

    // initialize variables
    int val1, val2;
    char op = 0;

    // print input prompt
    cout << "Please enter two single digits in either digit or string format seperated by an operator (ex. two + 2) (supported operators are + - * /): ";

    // gather all variables
    val1 = getNumber();
    cin >> op;
    val2 = getNumber();

    // initialize variables
    string outputOperator;
    double result;

    // switch based on op
    switch(op) {

        // addition
        case '+':
            
            // set outputOperator and calculate result
            outputOperator = "sum of ";
            result = val1 + val2;
            break;
        
        // subtraction
        case '-':

            // set outputOperator and calculate result
            outputOperator = "difference of ";
            result = val1 - val2;
            break;

        // multiplication
        case '*':

            // set outputOperator and calculate result
            outputOperator = "product of ";
            result = val1 * val2;
            break;

        // division
        case '/':

            // set outputOperator and calculate result
            outputOperator = "ratio of ";
            result = val1 / val2;
            break;

        // default
        default:

            // throw error
            error("invalid operator");

    }

    // print output
    cout << "The " << outputOperator << val1 << " and " << val2 << " is " << result << "\n";

}