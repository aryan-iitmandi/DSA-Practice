#include<bits/stdc++.h>
using namespace std;

// brute force
// Time: O(n^2)
// Space: O(1)
vector<int> twoSum0(vector<int> &arr, int sum){
    for(int i=0; i<arr.size(); i++){
        for(int j=i; j<arr.size(); j++){
            if(arr[i] + arr[j] == sum && i != j){
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

// optimal
// Time: O(n)
// Space: O(n)
vector<int> twoSum1(vector<int> &arr, int sum){
    unordered_map<int, int> map;
    
    for(int i=0; i<arr.size(); i++){
        int compliment = sum - arr[i];

        if(map.find(compliment) != map.end()){ 
            return {arr[map[compliment]], arr[i]};
        }

        map[arr[i]] = i;
    }
    return {-1, -1};
}

// better than brute force
// Time: O(nlogn)
// Space: O(n)
vector<int> twoSum2(vector<int> &arr, int sum){
    int n = arr.size();

    vector<pair<int, int>> v;
    for(int i=0; i<n; i++)  v.push_back({arr[i], i});

    sort(v.begin(), v.end());

    int l = 0, r = n - 1;
    while(l < r){
        int s = v[l].first + v[r].first;
        if(s == sum)  return {v[l].second, v[r].second};
        if(s < sum)     l++;
        else            r--;
    }
    return {-1, -1};
}

int main(){
    vector<int> arr;
    int ip;
    while (cin >> ip){
        arr.emplace_back(ip);
    }

    int target = arr.back();
    arr.pop_back();

    // vector<int> result = twoSum0(arr, target);
    vector<int> result = twoSum1(arr, target);
    // vector<int> result = twoSum2(arr, target);
    cout << result[0] << " " << result[1] << endl;
    return 0;    
}