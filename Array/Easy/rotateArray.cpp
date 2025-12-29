#include<bits/stdc++.h>
using namespace std;

// Time Complixity: O(n)
// Space Complixity: O(1)
void rotateArray(vector<int> &arr){
    int n = arr.size();
    if(n == 0)  return;
    int temp = arr[0];

    for(int i=1; i<=n-1; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}

// Time Complixity: O(n)
// Space Complixity: O(n) if k approach to n
void rotateArrayByK(vector<int> &arr, int k){
    int n = arr.size();
    if(n == 0)  return;
    k = k % n;

    int temp[k];
    for(int i=0; i<=k-1; i++){
        temp[i] = arr[i];
    }
    
    for(int i=k; i<=n-1; i++){
        arr[i-k] = arr[i];
    }
    
    for(int i=0; i<=k-1; i++){
        arr[n-k+i] = temp[i];
    }
}

// Time Complixity: O(n)
// Space Complixity: O(1) no extra temp arr :)
void rotateArrayByKOptimal(vector<int> &arr, int k){
    int n = arr.size();
    if(n == 0)  return;
    k = k % n;

    // reverse whole arr
    reverse(arr.begin(), arr.end());
    // reverse first n-k elements
    reverse(arr.begin(), arr.end() - k);
    // reverse last k elements
    reverse(arr.end() - k, arr.end());
}

int main(){
    vector<int> arr;
    int ip;

    while(cin >> ip){
        arr.push_back(ip);
    }

    // rotateArray(arr);
    // rotateArrayByK(arr, 3);
    rotateArrayByKOptimal(arr, 3);
    for(auto it: arr){
        cout << it << " ";
    }
    return 0;
}