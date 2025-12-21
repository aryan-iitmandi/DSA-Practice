#include<bits/stdc++.h>
using namespace std;

// Time Complixity: O(log10n)
// Space Complixity: O(1)
int reverseDigit(int n){
    int revNum = 0;
    while(n != 0){
        int lastDigit = n % 10;
        revNum = revNum * 10 + lastDigit;
        n = n / 10;
    }
    return revNum;
}

bool checkPalindrome(int n){
    return (n == reverseDigit(n));
}

int main(){
    int n;
    cin >> n;
    cout << checkPalindrome(n);
    return 0;
}