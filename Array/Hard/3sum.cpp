#include<bits/stdc++.h>
using namespace std;

// Time: O(n^3)
// Space: O(k) k unique triplets
vector<vector<int>> threeSum(vector<int> &arr){
    int n = arr.size();
    set<vector<int>> uniqueTriplets;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[i] + arr[j] + arr[k] == 0){
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    uniqueTriplets.insert(temp);
                }
            }
        }
    }
    return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
}

// Time: O(n^2)
// Space: O(n)
vector<vector<int>> threeSum1(vector<int> &arr, int target){
    int n = arr.size();
    set<vector<int>> resultSet;
    
    for(int i=0; i<n;i++){
        unordered_map<int, int> pastData;
        for(int j=i+1; j<n; j++){
            int compliment = target - (arr[i] + arr[j]);

            if(pastData.find(compliment) != pastData.end()){
                vector<int> triplet = {arr[i], arr[j], compliment};
                sort(triplet.begin(), triplet.end());
                resultSet.insert(triplet);
            }
            pastData[arr[j]];
        }
    }
    return vector<vector<int>>(resultSet.begin(), resultSet.end());
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip){
        arr.push_back(ip);
    }

    vector<vector<int>> result = threeSum1(arr, 0);

    for (auto &triplet : result) {
        for (int val : triplet) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}