#include<bits/stdc++.h>
using namespace std;

// Time: O(n)
// Space: O(n)
int majorityElement0(vector<int> &arr){
    unordered_map<int, int> map;
    for(int i: arr){
        map[i]++;
    }

    for(auto &pair: map){
        if(pair.second > arr.size() / 2)
            return pair.first;
    }
    return -1;
}

// int majorityElement1(vector<int> &arr){
//     int candidate = -1, count = 0;

//     for(auto num: arr){
        
//         if(count == 0){
//             candidate = num;
//             count = 1;
//         }

//         else if(num == candidate)
//             count++;
        
//         else
//             count--;
//     }
//     return candidate; // if majority is gaurenteed (>n/2)
// }

// Time: O(n)
// Space: O(1)
int majorityElement2(vector<int> &arr){
    int candidate = -1, count = 0;

    for(auto num: arr){
        
        if(count == 0){
            candidate = num;
            count = 1;
        }

        else if(num == candidate)
            count++;
        
        else
            count--;
    }
    // return candidate; // if majority is not gaurenteed, verify it
    count = 0;
    for(auto num: arr){
        if(num == candidate)
            count++;
    }
    if(count > arr.size() / 2) 
        return candidate;
    return -1;
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)    arr.emplace_back(ip);

    // cout << majorityElement0(arr);
    // cout << majorityElement1(arr);
    cout << majorityElement2(arr);
    return 0;
}