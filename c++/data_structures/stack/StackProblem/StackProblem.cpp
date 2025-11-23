#include <iostream>
#include "logger.hpp"
#include "Stack.h"
#include "CheckBalance.h"  

using namespace std;

int main() {
    cout << "Enter the brackets — ()[]{} :\n";
    string input;
    cin >> input;

    if (isBalanced(input)) {
        cout << "Balanced!\n";
    }
    else {
        cout << "Not Balanced!\n";
    }

    return 0;
}
