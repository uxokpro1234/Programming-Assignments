#include <iostream>
#include <vector>

using namespace std;

vector<int> dividers;
//when int j = 0, it doesnt work :( fak you
void divide(int i) {
    for (int j = 1; j <= i; j++) {
        if (i % j == 0) {
            dividers.push_back(j);
            cout << j << " ";
        }
    }
    cout << endl;
}

void findDividers() {
    cout << "Dividers for both numbers: ";
    for (int i = 0; i < dividers.size(); i++) {
        for (int j = i + 1; j < dividers.size(); j++) {
            if (dividers[i] == dividers[j]) {
                cout << dividers[i] << " ";
            }
        }
    }
}

int main() {
    int a, b;
    string c;

    while (true) {
        cout << "Enter two natural numbers: ";
        cin >> a >> b;

        // Incorrect data type
        if (cin.fail()) {
            cout << "Error: incorrect data type!" << endl;
            return 0;
        }

        // Invalid numbers
        if (a <= 0 || b <= 0) {
            cout << "Error: numbers must be natural numbers!!!" << endl;
            return 0;
        }

        cout << a << " " << b << endl;

        divide(a);
        divide(b);
        findDividers();

        cout << endl;
        cout << "Do you want to continue? Y/n: ";
        cin >> c;
        
        // exits
        if (c == "n" || c == "N") {
            cout << "Okay, goodbye!" << endl;
            break;
        }
        // starts again
        if (c == "y" || c == "Y") {
            dividers.clear();
            cout << endl;
            continue;
        }

        cout << "Error: please enter Y or n!" << endl;
    }

    return 0;
}
