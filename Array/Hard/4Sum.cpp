#include<bits/stdc++.h>
using namespace std;

// sorting + 2 pointer
// Time: O(n^3)
// Space: O(1)
vector<vector<int>> fourSum(vector<int> &arr, int target){
    int n = arr.size();
    vector<vector<int>> resultSet;
    sort(arr.begin(), arr.end());

    for(int i=0; i<n-4; i++){
        if(i > 0 && arr[i] == arr[i-1])     continue;
        
        for(int j=i+1; j<n-3; j++){
            if(arr[j] == arr[j+1])     continue;

            int l = j + 1, r = n - 1;

            while(l < r){ 
                int sum = arr[i] + arr[j] + arr[l] + arr[r];

                if(sum == target){
                    resultSet.push_back({arr[i], arr[j], arr[l], arr[r]});

                    while(l < r && arr[l] == arr[l+1]) l++;
                    while(l < r && arr[l] == arr[r-1]) r--;

                    l++;
                    r--;
                }

                else if(sum < target)   l++;
                else    r--;
            }
        }
    }
    return resultSet;
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)    arr.push_back(ip);

    int target = arr.back();
    arr.pop_back();
    
    vector<vector<int>> result = fourSum(arr, target);
    
    for(auto &quad: result){
        for(auto val: quad){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}