#include<bits/stdc++.h>
using namespace std;

int singleAppearence(vector<int> &arr){
    int n = arr.size();
    int low = 1, high = n - 2;

    if(n == 1)  return arr[0];
    if(arr[0] != arr[low])  return arr[0];
    if(arr[high] != arr[n-1])  return arr[n-1];

    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1])    return arr[mid];

        if(((mid%2 == 1) && (arr[mid] == arr[mid-1]))  || 
            ((mid%2 == 0) && (arr[mid] == arr[mid+1])))     low = mid + 1;

        else    high = mid -1;
    }
    return -1;
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)    arr.emplace_back(ip);

    cout << singleAppearence(arr);
    return 0;
}