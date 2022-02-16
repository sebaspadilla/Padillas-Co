#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <limits>

using namespace std;

namespace tools
{
    template <typename T>
    void safeCin(T& destiny) {
        while (!(cin >> destiny)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.  Try again: ";
        }
    }
}

#endif