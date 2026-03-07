#include<bits/stdc++.h>
using namespace std;

// time: O(log n)
// space: O(1)
int insert(vector<int> &arr, int target){
    int low = 0, high = arr.size() -1;
    int ans = arr.size(); // if target is greater than all elements, it will be inserted at the end

    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] >= target){
            ans = mid; // potential position to insert
            high = mid - 1; // search in the left half
        }
        else{
            low = mid + 1; // search in the right half
        }
    }
    return ans; 
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)    arr.emplace_back(ip);
    int target = arr.back();
    arr.pop_back();

    cout << insert(arr, target) << endl;
    return 0;
}