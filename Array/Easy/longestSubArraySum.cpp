#include<bits/stdc++.h>
using namespace std;

// used sliding window logic
// only positive sum k, 
// sliding left pointer forward ensures sum decreases
// sliding right pointer forward ensured sum increases
// therefore sliding window works
// Time O(n)
// Space O(1)
int longestSubArrSumPositive(vector<int> &arr, int k){
    int n = arr.size();
    int l = 0, maxLen = 0, sum = 0;

    // iterate right pointer
    for(int r=0; r<n; r++){
        sum += arr[r];
        // if sum exceeds, shrink from left until sum
        while(sum > k){
            sum -= arr[l];
            l++;
        }
        // update answer
        if(sum == k){
            maxLen = max(maxLen, r-l+1);
            cout << "Possible indices ==> "<< "Left: " << l << " Right: " << r << " Length: " << r-l+1 << endl;
        }
    }
    return maxLen;
}

// if sum is anything positive or negative
// sliding window fails because moving lt/rt pointer dosn't ensures sum increase or decrease
// Time: O(n)
// Space: O(n)
int longestSubArrAll(vector<int> &arr, int k){
    int sum = 0;
    int maxLen = 0;
    unordered_map<int, int> mp; //key: prefix sum, value: index

    for(int i=0; i<arr.size(); i++){
        sum += arr[i];

        // Case 1: subarray starting from index 0 (special case)
        if(sum == k)
            maxLen = i + 1;
        
        // Case 2: subarray ending at i
        if(mp.find(sum-k) != mp.end()) // in map if find(key) does not exists, it return to end()
            maxLen = max(maxLen, i-mp[sum-k]);
        
        // store prefix sum only once
        if(mp.find(sum) == mp.end())
            mp[sum] = i;
    }
    return maxLen;
}

int main(){
    vector<int> arr;
    int ip; // start arr from 0
    while (cin >> ip){
        arr. emplace_back(ip);  
    }
    
    // cout << longestSubArrSumPositive(arr, 6);
    cout << longestSubArrAll(arr, 3);
    return 0;
}