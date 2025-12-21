#include<bits/stdc++.h>
using namespace std;

// Time Complixity: O(sqrt(n))
bool checkPrime(int n){
    int count = 0;
    for(int i=1; i*i<=n; i++){
        if(n%i == 0){
            count++;
            if(n/i != i)    count ++;
        }
    }
    if(count == 2)  return true;
    return false;
}

int main(){
    int n;
    cin >> n;
    cout << checkPrime(n);
    return 0;
}