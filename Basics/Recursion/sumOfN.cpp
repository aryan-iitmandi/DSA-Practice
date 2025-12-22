#include<bits/stdc++.h>
using namespace std;

// Time Complixity: O(n)
// Space Complixity: O(n)
int sumOfN(int n){
    if(n == 1)  return 1;
    return n + sumOfN(n - 1);
}

// Time Complixity: O(1)
// Space Complixity: O(1)
int sumOfNUsingFormulae(int n){
    return n*(n-1)*0.5;
}

int main(){
    int n;
    cin >> n;
    cout << sumOfN(n) << endl;
    cout << sumOfNUsingFormulae(n);
    return 0;
}