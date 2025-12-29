#include<bits/stdc++.h>
using namespace std;

void moveZeroToEnd(vector<int> &arr){
    int n = arr.size();
    if(n == 0)  return;

    int i = -1; // tracks length of non-zero elements 
    for(int j=0; j<=n-1; j++){
        if(arr[j] != 0){
            i++;
            arr[i] = arr[j];
        }
    }
    i++;
    while(i < n){
        arr[i++] = 0;
    }
}

int main(){
    vector<int> arr;
    int ip;

    while(cin >> ip){
        arr.push_back(ip);
    }

    moveZeroToEnd(arr);
    for(auto it: arr){
        cout << it << " ";
    }
    return 0;
}