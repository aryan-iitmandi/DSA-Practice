#include<bits/stdc++.h>
using namespace std;

bool splitPossible(vector<int> &arr, int nofSplit, int maxSum){
    int currentSum = 0;
    int currentSplits = 1;

    for(int i=0; i<arr.size(); i++){
        if(arr[i] > maxSum)     return false;
        if(currentSum + arr[i] <= maxSum)   currentSum += arr[i];
        else{
            currentSplits++;
            currentSum = arr[i];
        }
        if(currentSplits > nofSplit)    return false;
    }
    return true;
}

int splitArray(vector<int> &arr, int k){
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = 0;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(splitPossible(arr, k, mid)){
            ans = mid;
            high = mid - 1;
        }   
        else    low = mid + 1; 
    }
    return ans;
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)    arr.emplace_back(ip);
    int k = arr.back();
    arr.pop_back();

    cout << splitArray(arr, k);
    return 0;
}