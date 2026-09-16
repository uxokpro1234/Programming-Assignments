#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//structure for storing coordinates of a point
struct Point {
    double x;
    double y;
};

//calculates the distance between two points
double distance(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;

    return sqrt(dx * dx + dy * dy);
}

//calculates the area of a triangle using its coordinates
double triangleArea(Point a, Point b, Point c) {
    double result =
        a.x * (b.y - c.y) +
        b.x * (c.y - a.y) +
        c.x * (a.y - b.y);

    return abs(result) / 2.0;
}

int main() {

    //variables for the three vertices
    Point A, B, C;
    // Repeat the program until the user chooses to stop
    while (true) {

        cout << "Enter coordinates of vertex A (x y): ";

        // Check if the input contains numbers
        if (!(cin >> A.x >> A.y)) {
            cout << "Error: incorrect input data!" << endl;
            return 0;
        }

        cout << "Enter coordinates of vertex B (x y): ";

        if (!(cin >> B.x >> B.y)) {
            cout << "Error: incorrect input data!" << endl;
            return 0;
        }

        cout << "Enter coordinates of vertex C (x y): ";

        if (!(cin >> C.x >> C.y)) {
            cout << "Error: incorrect input data!" << endl;
            return 0;
        }

        //calculate the area of the triangle
        double area = triangleArea(A, B, C);

        // If area is zero, the points are on the same line
        if (area == 0) {
            cout << "Error: the given points do not form a triangle!"
                 << endl;
            return 0;
        }

        //calculate the lengths of the three sides
        double sideBC = distance(B, C);
        double sideAC = distance(A, C);
        double sideAB = distance(A, B);

        //calculate all three heights
        double heightA = (2.0 * area) / sideBC;
        double heightB = (2.0 * area) / sideAC;
        double heightC = (2.0 * area) / sideAB;

        //print the results
        cout << fixed << setprecision(2);
        cout << endl;
        cout << "Triangle area: " << area << endl;
        cout << "Height from A: " << heightA << endl;
        cout << "Height from B: " << heightB << endl;
        cout << "Height from C: " << heightC << endl;
        cout << endl;

        //ask whether the user wants to repeat
        char answer;

        cout << "Do you want to continue? Y/n: ";
        cin >> answer;

        if (answer == 'n' || answer == 'N') {
            cout << "Okay, goodbye!" << endl;
            break;
        }

        if (answer != 'y' && answer != 'Y') {
            cout << "Error: please enter Y or n!" << endl;
            break;
        }

        cout << endl;
    }

    return 0;
}
