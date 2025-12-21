#include<bits/stdc++.h>
using namespace std;

// Function to count the number of digits in an integer

// Brute Force Approach
// Time Complexity: O(log10 n)
// Space Complexity: O(1)
int countDigit(int n){
    int count = 0;
    if(n == 0) return 1;
    while(n != 0){
        n = n/10;
        count++;
    }
    return count;
}

// Optimized Approach
// Time Complexity: O(1)
// Space Complexity: O(1)
int countDigitOptimized(int n){
    if(n == 0) return 1;
    return floor(log10(abs(n))) + 1;
}

int main(){
    int n;
    cin >> n;
    cout << countDigit(n) << endl;
    cout << countDigitOptimized(n) << endl;
    return 0;
}