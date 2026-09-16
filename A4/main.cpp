#include <iostream>
#include <limits>

using namespace std;

// removes everything left in the input until the next line.
void ignoreLine() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// checks if the last input failed and fixes cin if needed.
bool clearFailedExtraction() {
    if (!cin) {
        if (cin.eof()) {
            exit(0);
        }

        cin.clear();
        ignoreLine();
        return true;
    }

    return false;
}

// keeps asking until the user enters a valid integer.
int requestInt(string message) {
    while (true) {
        cout << message;

        int input;
        cin >> input;

        if (clearFailedExtraction()) {
            cout << "Invalid input! Try again...\n";
            continue;
        }

        ignoreLine();
        return input;
    }
}

int main() {

start:

    int amountOfIntegers = requestInt(
        "Enter how many integers you want to check: "
    );

    // make sure the user actually wants to enter something.
    if (amountOfIntegers <= 0) {
        cout << "Please enter a number greater than 0.\n\n";
        goto start;
    }

    cout << "Now enter " << amountOfIntegers
         << " integer(s) one by one.\n";

    int numbers[amountOfIntegers];

    // start with the biggest possible int so the first number
    // entered will always become the smallest.
    int smallestInteger = numeric_limits<int>::max();

    // keeps track of how many times the smallest number appears.
    int amountOfSmallestIntegers = 0;

    // read all the numbers and find the smallest one.
    for (int i = 0; i < amountOfIntegers; i++) {

        int number = requestInt(
            "Input integer " + to_string(i + 1) + ": "
        );

        numbers[i] = number;

        if (number < smallestInteger) {
            smallestInteger = number;
        }
    }

    // count how many times the smallest number appears.
    for (int i = 0; i < amountOfIntegers; i++) {
        if (numbers[i] == smallestInteger) {
            amountOfSmallestIntegers++;
        }
    }

    cout << "\nThe smallest integer is " << smallestInteger
         << " and it appears " << amountOfSmallestIntegers
         << " time(s).\n";

    int continueInt = requestInt(
        "\nWould you like to try again? 0/1: "
    );

    if (continueInt != 0) {
        goto start; // nothing wrong with a little goto!
    }

    return 0;
}
