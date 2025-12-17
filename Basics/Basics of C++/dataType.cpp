#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Different Data Types in C++
    int a = 10;               // Integer data type
    float b = 5.5f;          // Floating point data type
    double c = 9.99;         // Double precision floating point
    char d = 'A';            // Character data type
    bool e = true;           // Boolean data type

    // Output the values and their sizes
    cout << "Integer a: " << a << ", Size: " << sizeof(a) << " bytes\n";
    cout << "Float b: " << b << ", Size: " << sizeof(b) << " bytes\n";
    cout << "Double c: " << c << ", Size: " << sizeof(c) << " bytes\n";
    cout << "Character d: " << d << ", Size: " << sizeof(d) << " bytes\n";
    cout << "Boolean e: " << e << ", Size: " << sizeof(e) << " bytes\n\n";

    string str;
    getline(cin, str);
    cout << str << "\n";

    return 0;
}