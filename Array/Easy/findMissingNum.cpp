#include<bits/stdc++.h>
using namespace std;

// Time Complixity: O(n)
// Space Complixity: O(1)
// overflow if n is large
int findMissingNum1(vector<int> &arr){
    int n = arr.size();
    if(n == 1)  return -1;
    int expectedSum = n*(n+1)/2;
    int actualSum = 0;
    for(int i=0; i<=n-1; i++){
        actualSum = actualSum + arr[i];
    }
    return expectedSum - actualSum;
}

// Time Complixity: O(n)
// Space Complixity: O(1)
int findMissingNum2(vector<int> &arr){
    int n = arr.size();
    if(n == 1)  return -1;
    int xorAll = 0, xorArr = 0;
    for(int i=0; i<=n-2; i++){
        xorAll = xorAll ^ i;
        xorArr = xorArr ^ arr[i];
    }
    xorAll = xorAll ^ n-1;
    return xorAll ^ xorArr;
}

int main(){
    vector<int> arr;
    int ip; // start arr from 0
    while (cin >> ip){
        arr. emplace_back(ip);  
    }

    // cout << findMissingNum1(arr);
    cout << findMissingNum2(arr);
    
    return 0;
}