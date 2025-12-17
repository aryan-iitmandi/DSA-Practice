#include <bits/stdc++.h>
using namespace std;

// Pass by Value - function receives a copy of the variable
void passbyValue(int x) {
    x = 100;  // changes only the local copy
    cout << "Inside passbyValue: " << x << endl;
}

// Pass by Reference - function receives reference to the original variable
void passbyReference(int &x) {
    x = 100;  // changes the original variable
    cout << "Inside passbyReference: " << x << endl;
}

// Pass by Const Reference - function receives reference but cannot modify
void passbyConstReference(const int &x) {
    // x = 100;  // This would cause a compilation error
    cout << "Inside passbyConstReference: " << x << endl;
}

int main() {
    int num = 5;
    
    cout << "Original value: " << num << endl << endl;
    
    // Pass by Value
    cout << "--- Pass by Value ---" << endl;
    passbyValue(num);
    cout << "After passbyValue: " << num << endl << endl;
    
    // Pass by Reference
    cout << "--- Pass by Reference ---" << endl;
    passbyReference(num);
    cout << "After passbyReference: " << num << endl << endl;
    
    // Pass by Const Reference
    cout << "--- Pass by Const Reference ---" << endl;
    passbyConstReference(num);
    cout << "After passbyConstReference: " << num << endl;
    
    return 0;
}