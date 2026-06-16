#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> powerSet(vector<int> &arr){
    int n = arr.size();
    vector<vector<int>> result;
    for(int mask = 0; mask < (1 << n); mask++){
        vector<int> subSet;
        for(int i=0; i<n; i++){
            if(mask & (1 << i))     subSet.push_back(arr[i]);
        }
        result.push_back(subSet);
    }
    return result;
}

int main(){
    vector<int> arr = {4, 8, 12};
    vector<vector<int>> result = powerSet(arr);
    for(auto subSet: result){
        for(auto it: subSet){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}