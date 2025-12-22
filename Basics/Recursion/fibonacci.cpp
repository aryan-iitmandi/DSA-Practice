#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n <= 1)    return n;
    return factorial(n - 1) + factorial(n - 2);
}

int main(){
    int n;
    cin >> n;
    cout << factorial(n);
    return 0;
}