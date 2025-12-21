#include<bits/stdc++.h>
using namespace std;

// Time Complixity: O(log10n)
// Space Complexity: O(1)
int reverseDigit(int n){
    int revNum = 0;
    while(n != 0){
        int lastDigit = n % 10;
        revNum = revNum * 10 + lastDigit;
        n = n / 10;
    }
    return revNum;
}

int main(){
    int n;
    cin >> n;
    cout << reverseDigit(n);
    return 0;
}