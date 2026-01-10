#include<bits/stdc++.h>
using namespace std;

// brute force
// Time: O(n^2)
// Space: O(1)
int maximumSubArray0(vector<int> &arr){
    int maxSum = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        int sum = 0;
        for(int j=i; j<arr.size(); j++){
            sum += arr[j];
            cout << "sum " << sum << " maxSum: " << maxSum << endl;
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

// kandane's algorithm
// Time: O(n)
// Space: O(1)
int maximumSubArray(vector<int> &arr){
    int maxSum = INT_MIN;
    int sum = 0;
    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
        // cout << "sum " << sum << " maxSum: " << maxSum << endl;
        maxSum = max(sum, maxSum);

        if(sum < 0)
            sum = 0;
    }
    return maxSum;
}

int maximumSubArrayWithPrint(vector<int> &arr){
    int maxSum = INT_MIN;
    int sum = 0;
    int start = 0;
    int l = -1, r = -1;

    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
        
        // whenever maxSum updated, also update index of new maxSum sub-array l and r
        if(sum > maxSum){
            maxSum = sum;
            l = start;
            r = i;
        }
        
        // if sum goes -ve, reset it to 0 and update start index to i + 1
        if(sum < 0){
            sum = 0;
            start = i + 1;
        }
    }
    for(int i=l; i<=r; i++){
        cout << arr[i] << " ";
    }   
    cout << endl;
    return maxSum;
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)
        arr.emplace_back(ip);
    
    // cout << maximumSubArray0(arr);
    // cout << maximumSubArray(arr);
    cout << maximumSubArrayWithPrint(arr);
    return 0;
}