#include<bits/stdc++.h>
using namespace std;

int peakElement(vector<int> &arr){
    int low = 0, high = arr.size() - 1;

    while(low < high){
        int mid = low + (high-low)/2;
        
        if(arr[mid] < arr[mid+1])   low = mid+1;

        else    high = mid;
    }
    return arr[low];
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)    arr.emplace_back(ip);

    cout << peakElement(arr);
    return 0;
}