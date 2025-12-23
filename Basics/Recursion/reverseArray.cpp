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

void reverseArrayRecursion(vector<int> &arr, int l, int r){
    if(l >= r) return;
    swap(arr[l], arr[r]);
    reverseArrayRecursion(arr, l+1, r-1);
}

int main(){
    vector<int> arr;
    int ip;
    
    while(cin >> ip){
        arr.push_back(ip);
    }
    // reverseArray(arr);
    reverseArrayRecursion(arr, 0, arr.size()-1);
    // reverseArrayInBuilt(arr);

    for(auto it: arr){
        cout << it << " ";
    }
    return 0;
}