#include<bits/stdc++.h>
using namespace std;

int xorUpto(int n){
    switch(n % 4){
        case 0: return n;
        case 1: return 1;
        case 2: return n+1;
        default: return 0;
    }
}

int findXOR(int low, int high){
    return xorUpto(high) ^ xorUpto(low -1);
}

int main(){
    int low, high;
    cin >> low >> high;

    cout << findXOR(low, high);
    return 0;
}