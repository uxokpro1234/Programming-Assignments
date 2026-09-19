#include <iostream>
#include <vector>
#include <limits>

using namespace std;
vector<int> dividers;

//when int j = 0, it doesnt work(cant divide by 0) :( fak you
//devider logic

void divide(int i) {
    for (int j = 1; j <= i; j++) {
        //if number divides by j without decimals, it works(is divideable) !!!
        if (i % j == 0) {
            //adds dividable number into an array list
            dividers.push_back(j);
            cout << j << " ";
        }
    }

    cout << endl;
}

//finds similar dividers in array dividers and outputs them
void findDividers() {
    cout << "Dividers for both numbers: ";
    //starts scan from 1st element [0] for arrays.
    for (int i = 0; i < dividers.size(); i++) {
        //goes trough entire array to find similar numbers
        for (int j = i + 1; j < dividers.size(); j++) {
            //if start scan number equals to another number from array, it gets printed out
            if (dividers[i] == dividers[j]) {
                cout << dividers[i] << " ";
            }
        }
    }
}

int main() {
    int a, b;
    string c;
    //i looped main code, so it would repeat itself forever. Yes while true. Never left me behind.
    while (true) {
        //input stream with text
        cout << "Enter two natural numbers: ";
        cin >> a >> b;

        //incorrect data type
        if (cin.fail()) {
            cout << "Error: incorrect data type!" << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        //invalid numbers
        if (a <= 0 || b <= 0) {
            cout << "Error: numbers must be natural numbers!!!" << endl;
            continue;
        }
        //debug
        //cout << a << " " << b << endl;
        //my functions
        //we divide both numbers, which not only divides them, but also adds em into an array
        divide(a);
        divide(b);
        //now we are scanning array for repetitions
        findDividers();
        //yea i ended line like this afterwards
        cout << endl;

        //heres the infinite loop part. If Y/y, we continue the loop. if N/n. we quit
        cout << "Do you want to continue? Y/n: ";

        //you cant get rid of me
        while (true){
            cin >> c;

            //exits
            if (c == "n" || c == "N") {
                cout << "Okay, goodbye!" << endl;
                //break; doesnt work here cuz of while priorities :(
                //exits all loops
                return 0;
            }

            //starts again
            if (c == "y" || c == "Y") {
                //if i didnt clear dividers, they would stack like an eiffel tower, ruining output.
                dividers.clear();
                cout << endl;
                //breaks 2nd loops, resuming loop1
                break;
            }

            //yea if you entered wrong data, it would say it
            cout << "Error: please enter Y or n!" << endl;
            cout << "Do you want to continue? Y/n: ";
        }
    }
    return 0;
}
