#include<bits/stdc++.h>
using namespace std;

// brute force
// time : O(n)
// space: O(n)
pair<int, int> findRepeatAndMissing(vector<int> &arr){
    unordered_map<int, int> freq;
    for(int num: arr)    freq[num]++;
    int repeat = -1, missing = -1;

    for(int i=1; i<=arr.size(); i++){
        if(freq[i] == 0)    missing = i;
        else if(freq[i] > 1)    repeat = i;
    }
    return {repeat, missing};
}

// mathematical approach
// time : O(n)
// space: O(1)
pair<int, int> findRepeatAndMissing1(vector<int> &arr){
    int n = arr.size();
    long long sumN = (n*(n+1))/2;
    long long sumSqN = (n*(n+1)*(2*n+1))/6;
    long long sumArr = 0, sumSqArr = 0;

    for(auto it: arr){
        sumArr += it;
        sumSqArr += (long long)it*it;
    }

    long long diff = sumN - sumArr; // missing - repeat
    long long sqDiff = sumSqN - sumSqArr; // missing^2 - repeat^2
    
    // missing^2 - repeat^2 = (missing - repeat)(missing + repeat)
    // missing + repeat = sqDiff / diff
    long long sum = sqDiff / diff;
    long long missing = (diff + sum) / 2;
    long long repeat = sum - missing;
    return {repeat, missing};
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)    arr.emplace_back(ip);

    // pair<int, int> ans = findRepeatAndMissing(arr);
    pair<int, int> ans = findRepeatAndMissing1(arr);
    cout << "Repeat: " << ans.first << ", Missing: " << ans.second << endl;
    return 0;
}