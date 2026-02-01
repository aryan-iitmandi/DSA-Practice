#include<bits/stdc++.h>
using namespace std;

// Brute force
// Time: O(n^3)
// Space: O(k) k unique triplets
vector<vector<int>> threeSum0(vector<int> &arr){
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

// hashing (similar to 2-sum)
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

// sorting + 2 pointer
// Time: O(n^2)
// Space: O(1)
vector<vector<int>> threeSum2(vector<int> arr, int target){
    int n = arr.size();
    vector<vector<int>> resultSet;
    sort(arr.begin(), arr.end());

    for(int i=0; i<n-3; i++){
        if(i > 0 && arr[i] == arr[i-1])     continue;

        int l = i + 1, r = n - 1;
        while(l < r){
            int sum = arr[i] + arr[l] + arr[r];

            if(sum == target){
                resultSet.push_back({arr[i], arr[l], arr[r]});
                
                while(l < r && arr[l] == arr[l+1]) l++;
                while(l < r && arr[l] == arr[r-1]) r--;
    
                l++;
                r--;
            } 

            else if(sum < target)   l++;
            else    r--;
        }
    }
    return resultSet;
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip){
        arr.push_back(ip);
    }

    // vector<vector<int>> result = threeSum0(arr);
    // vector<vector<int>> result = threeSum1(arr, 0);
    vector<vector<int>> result = threeSum2(arr, 0);

    for (auto &triplet : result) {
        for (int val : triplet) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}