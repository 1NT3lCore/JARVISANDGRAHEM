#include <iostream>
#include "convex_hull.h"
using namespace std;

int main() {
    int n;
    cout << "Enter the number of points (should be a natural number and >= 3): ";
    string input;
    getline(cin, input);

    while (!is_int(input)) {
        cout << "Invalid input. Please enter a valid natural number: ";
        getline(cin, input);
    }

    n = stoi(input);

    if (n < 3) {
        cout << "Convex hull not possible with less than 3 points!";
        return 0;
    }

    vector<point2d> points(n);

    cout << "Enter the points (x,y):" << endl;
    for (auto& pt : points) {
        string x_str, y_str;
        getline(cin, input);

        stringstream ss(input);
        getline(ss, x_str, ',');
        getline(ss, y_str, ',');

        if (!is_int(x_str) || !is_int(y_str)) {
            cout << "Invalid input, please enter valid integers separated by a comma." << endl;
            return 1;
        }

        pt.x = stoi(x_str);
        pt.y = stoi(y_str);
    }

    int choice;
    cout << "Choose the algorithm to compute the convex hull:" << endl;
    cout << "1. Graham's Scan" << endl;
    cout << "2. Jarvis's March" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    vector<point2d> ch;
    if (choice == 1) {
        ch = graham_scan(points);
    }
    else if (choice == 2) {
        ch = jarvis_march(points);
    }
    else {
        cout << "Invalid choice. Exiting program." << endl;
        return 1;
    }

    cout << "Convex Hull Points:" << endl;
    cout << ch.size() << endl;

    for (auto pt : ch) {
        cout << pt.x << ' ' << pt.y << endl;
    }
    return 0;
}