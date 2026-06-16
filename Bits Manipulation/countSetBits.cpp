#include<bits/stdc++.h>
using namespace std;

// count set bit
// O(log n)
int countSetBits(int n){
    int count = 0;
    while(n > 0){
        if((n & 1) == 1)    count++;
        n = n >> 1;
    }
    return count;
}

// Brian Kernighan's algorithm, which runs once per set bit
// O(log k) k = set bits
int countSetBits1(int n){
    int count = 0;
    while(n > 0){
        n = n & (n-1); // removes lowest bit
        count++;
    }
    return count;
}

int main(){
    int n;
    cin >> n;

    cout << countSetBits1(n);
    return 0;
}