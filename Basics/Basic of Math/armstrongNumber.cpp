#include<bits/stdc++.h>
using namespace std;

int countDigitOptimized(int n){
    if(n == 0) return 1;
    return floor(log10(abs(n))) + 1;
}

// Time Complixity: O(log10n)
// Space Complixity: O(1)
bool armstrongNumber(int n){
    int temp = n;
    int digits = countDigitOptimized(n);
    int sum = 0;
    while (n != 0){
        sum = sum + pow((n % 10), digits);
        n = n / 10;
    }
    if (sum == temp)    return true;
    else return false;
}

int main(){
    int n;
    cin >> n;
    cout << armstrongNumber(n);
    return 0;
}