#include<bits/stdc++.h>
using namespace std;

// Time: O(n)
// Space: O(n)
vector<int> majorityThree0(vector<int> &arr){
    if(arr.size() == 0) return {-1};
    unordered_map<int, int> freq;
    vector<int> result;
    for(auto it: arr){
        freq[it]++;
    }
    for(auto &it: freq){
        if(it.second > arr.size()/3){
            result.push_back(it.first);
        }
    }
    return result;
}

// boyer-moore voting algorithm
// Time: O(n)
// Space: O(1)
pair<int, int> majorityThree1(vector<int> &arr){
    int n = arr.size();
    int candidate1 = -1, candidate2 = -1;
    int count1 = 0, count2 = 0;

    for(auto x: arr){
        if(count1 == 0){
            candidate1 = x;
            count1 = 1;
        }
        else if(count2 == 0){
            candidate2 = x;
            count2 = 1;
        }

        else if(x == candidate1)    count1++;
        else if(x == candidate2)    count2++;

        else{
            count1--;
            count2--;
        }
    }

    count1 = count2 = 0;
    for(auto x: arr){
        if(x == candidate1)     count1++;
        else if(x == candidate2)    count2++;
    }
    pair<int, int> result = {-1, -1};
    if(count1 > n/3)    result.first = candidate1;
    if(count2 > n/3)    result.second = candidate2;

    return result;
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip){
        arr.push_back(ip);
    }

    // vector<int> result = majorityThree0(arr);
    // for(auto it: result)    cout << it << " ";

    pair<int, int> result = majorityThree1(arr);
    cout << result.first << " " << result.second;
    return 0;
}