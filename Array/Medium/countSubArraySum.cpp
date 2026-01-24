#include<bits/stdc++.h>
using namespace std;

// brute force
// time: O(n^2)
// space: O(1)
int countSubArraySum(vector<int> &arr, int target){
    int n = arr.size();
    int count = 0;

    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            if(sum == target){
                count++;
            }
        }
    }
    return count;
}

// optimal
// time: O(n)
// space: O(n)
int countSubArraySum1(vector<int> &arr, int target){
    unordered_map<int, int> freq;
    int sum = 0;
    int count = 0;

    // base case to start sum from index 0
    freq[0] = 1;
    for(auto x: arr){
        sum += x;

        if(freq.find(sum-target) != freq.end()){
            count += freq[sum-target];
        }
        freq[sum]++;
    }
    return count;
}

int main(){
    vector<int> arr;
    int ip;
    while (cin >> ip){
        arr.emplace_back(ip);
    }
    int target = arr.back();
    arr.pop_back();

    // cout << countSubArraySum(arr, target) << endl;
    cout << countSubArraySum1(arr, target) << endl;
    return 0;    
}