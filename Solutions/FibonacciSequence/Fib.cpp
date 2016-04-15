// Author: Brett Holman
// Problem: Fibonacci Sequence -
//      Enter a number and have the program generate the Fibonacci sequence to that number or to the Nth number.
#include <iostream>

using namespace std;

// These are used to test agains the flags that are passed in.
const char option1 = 'a'; // Used to print out up unil this number
const char option2 = 'b'; // Used to limit the index that the sequence goes to.

void fibHelper(int &curValue, int &previousValue) {
    int tmp = curValue;
    curValue += previousValue;
    previousValue = tmp;
}

void fibUntilValue(const int limit, int curValue = 1, int previousValue = 0) {
    // Base case
    if(curValue >= limit)
        return;
    cout << curValue << " ";
    fibHelper(curValue, previousValue);
    fibUntilValue(limit, curValue, previousValue);
}

void fibUntilIndex(int index, int curValue = 1, int previousValue = 0) {
    // Base case
    if(index == 0)
        return;
    cout << curValue << " ";
    fibHelper(curValue, previousValue);
    fibUntilIndex(index - 1, curValue, previousValue);
}

void fibbSequence(const char& option, int num) {
    // Taking the liberty to print the first value here.
    cout << 0 << " ";
    // Subtracting 1 because the 0 has already been printed. 
    num--;
    switch(option) {
        case option1:
            fibUntilValue(num);
            break;
        case option2:
            fibUntilIndex(num);
            break;
        // There should never be a need for default at this point.
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        cerr << "There needs to be two arguments passed in to run this program" << endl;
        return -1;
    }

    string option = *(argv + 1);

    // Verify that the option flag was not
    if(option.length() > 1)
    {
        cout << "The option flag can not have a string of more than one lenth." << endl;
        return -1;
    }

    // Convert it to a char now after checking.
    char charOption = option[0];
    if(charOption != option1 && charOption != option2) {
        cout << "The option flag can only have the value of \"" << option1 << "\" or \"" << option2 << "\". Nothing else is supported." << endl;
        return -1;
    }

    // Convert second parameter into int.
    int value = atoi(*(argv + 2));
    if(value == 0 && *(argv + 2)[0] != 0) {
        cout << "The index or value that you are trying to access must be more than 0" << endl;
        return -1;
    }

    if(value < 0) {
        cout << "This program does not support negative a Fibonacci sequence" << endl;
        return -1;
    }

    if(value > 45) {
        cout << "This program does not support values larger than 45" << endl;
        return -1;
    }

    fibbSequence(charOption, value);

    return 0;
}
