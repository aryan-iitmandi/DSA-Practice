#include<bits/stdc++.h>
using namespace std;

void printNameNTimes(int n){
    if (n < 1) return;
    printNameNTimes(n - 1);
    cout << "Aryan " << endl;
}

void printNTo1(int n){
    if (n < 1) return;
    cout << n << endl;
    printNTo1(n - 1);
}

void print1ToN(int n){
    if (n < 1) return;
    print1ToN(n - 1);
    cout << n << endl;
}

int main(){
    int n;
    cin >> n;
    printNameNTimes(n);
    printNTo1(n);
    print1ToN(n);
    return 0;
}