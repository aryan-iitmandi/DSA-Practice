#include<bits/stdc++.h>
using namespace std;

// Time: O(n)
// Space: O(1)
int singleAppearence1(vector<int> &arr){
    int n = arr.size();
    int XOR = 0;
    for(auto it: arr){
        XOR = XOR ^ it;
    }
    return XOR;
}

// Time: O(n) + O(n)
// Space O(n)
int singleAppearence2(vector<int> &arr){
    int n = arr.size();
    unordered_map<int, int> freq;
    for(auto it: arr){
        freq[it]++;
    }
    for(auto it: freq){
        if (it.second == 1) return it.first;
    }
    return 0;
}

int main(){
    vector<int> arr;
    int ip; // start arr from 0
    while (cin >> ip){
        arr. emplace_back(ip);  
    }

    cout << singleAppearence1(arr);
    // cout << singleAppearence2(arr);
    
    return 0;
}