#include<bits/stdc++.h>
using namespace std;

// brute force
// time: O(n^2)
// space: O(1)
int subArrayXOR(vector<int> &arr, int target){
    int count  = 0;
    for(int i=0; i<arr.size(); i++){
        int xorSum = 0;
        for(int j=i; j<arr.size(); j++){
            xorSum ^= arr[j];
            if(xorSum == target)   count++;
        }
    }
    return count;
}

// optimal
// time: O(n)
// space: O(n)
int subArrayXOROptimal(vector<int> &arr, int target){
    unordered_map<int, int> prefixXOR;
    int xorSum = 0, count = 0;
    for(int i=0; i<arr.size(); i++){
        xorSum ^= arr[i];

        if(xorSum == target)   count++;

        if(prefixXOR.find(xorSum ^ target) != prefixXOR.end()){
            count += prefixXOR[xorSum ^ target];
        }
        
        prefixXOR[xorSum]++;
    }
    return count;
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)    arr.emplace_back(ip);

    int target = arr.back();
    arr.pop_back();

    // cout << subArrayXOR(arr, target) << endl;
    cout << subArrayXOROptimal(arr, target) << endl;
    return 0;
}