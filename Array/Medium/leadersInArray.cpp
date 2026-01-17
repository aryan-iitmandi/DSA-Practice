#include<bits/stdc++.h>
using namespace std;

// Time: O(n^2)
// Space: O(n)
vector<int> leadersInArray0(vector<int> &arr){
    vector<int> leaders;
    for(int i=0; i<arr.size(); i++){
        bool isLeader = true;
        for(int j=i; j<arr.size(); j++){
            // cout << arr[i] << " " << arr[j] << " " << isLeader << endl;
            if(arr[i] < arr[j]){
                isLeader = false;
            }
        }
        if(isLeader)    leaders.push_back(arr[i]);
    }
    for(auto it: leaders)   cout << it << " ";
    return leaders;
}

// Time: O(n)
// Space: O(n)
vector<int> leadersInArray1(vector<int> &arr){
    vector<int> leaders;
    int max = INT_MIN;
    for(int i=arr.size()-1; i>=0; i--){
        if(arr[i] > max){
            max = arr[i];
            leaders.push_back(max);
        }
    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
}


int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)
        arr.emplace_back(ip); 
    
    // leadersInArray0(arr);
    vector<int> result = leadersInArray1(arr);
    for(auto it: result)   cout << it << " ";
    return 0;
}