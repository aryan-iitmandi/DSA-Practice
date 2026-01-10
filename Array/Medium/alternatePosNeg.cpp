#include<bits/stdc++.h>
using namespace std;

// Time: O(n)
// Space: O(n)
void alternatePosNeg(vector<int> &arr){
    vector<int> pos, neg;

    for(int i=0; i<arr.size(); i++){
        if(arr[i] >= 0)     pos.push_back(arr[i]);
        if(arr[i] < 0)     neg.push_back(arr[i]);
    }

    int i = 0, p = 0, n = 0;
    while(p < pos.size() && n < neg.size()){
        arr[i++] = pos[p++];
        arr[i++] = neg[n++];
    }
    while(p < pos.size())   arr[i++] = pos[p++];
    while(n < neg.size())   arr[i++] = neg[n++];
    
    for(auto it: arr)   cout << it << " ";
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)
        arr.emplace_back(ip);
    
    alternatePosNeg(arr);
    return 0;
}