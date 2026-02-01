#include<bits/stdc++.h>
using namespace std;

// Time: O(n)
// Space: O(n)
int maxSubArrSum(vector<int> &arr, int target){
    unordered_map<int, int> prefixSum;
    int sum = 0, maxLen = 0;

    for(int i=0; i<arr.size(); i++){
        sum += arr[i];

        if(sum == target)   maxLen = i + 1;

        if(prefixSum.find(sum - target) != prefixSum.end()){
            maxLen = max(maxLen, i - prefixSum[sum - target]);
        }

        else    prefixSum[sum] = i;
    }
    return maxLen;
}

int maxSubArrSumWithPrint(vector<int> &arr, int target){
    unordered_map<int, int> prefixSum;
    int sum = 0, maxLen = 0;
    int l = -1, r = -1;
    prefixSum[0] = -1;

    for(int i=0; i<arr.size(); i++){
        sum += arr[i];

        if(sum == target && i + 1 > maxLen){
            maxLen = i + 1;
            l = 0;
            r = i;
        }   

        if(prefixSum.find(sum - target) != prefixSum.end()){
            int start = prefixSum[sum - target] + 1;
            int len = i - prefixSum[sum - target];

            if(len > maxLen){
                maxLen = len;
                l = start;
                r = i;
            }
        }

        if(prefixSum.find(sum) == prefixSum.end())   prefixSum[sum] = i;
    }

    if(l != -1){
        for(int i=l; i<=r; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return maxLen;
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)    arr.emplace_back(ip);

    int target = arr.back();
    arr.pop_back();

    cout << maxSubArrSum(arr, target);
    // cout << maxSubArrSumWithPrint(arr, target);

    return 0;
}