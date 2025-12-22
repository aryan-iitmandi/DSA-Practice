#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int>& arr){
    int l = 0;
    int r = arr.size() - 1;

    while(l < r){
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

void reverseArrayInBuilt(vector<int> &arr){
    reverse(arr.begin(), arr.end());
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip){
        arr.push_back(ip);
    }
    reverseArray(arr);
    for(auto it: arr){
        cout << it << " ";
    }
    // reverseArrayInBuilt(arr);
    return 0;
}