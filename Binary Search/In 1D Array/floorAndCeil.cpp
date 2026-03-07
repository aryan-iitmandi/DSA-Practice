#include<bits/stdc++.h>
using namespace std;

// time: O(log n)
// space: O(1)
pair<int, int> floorAndCeil(vector<int> &arr, int target){
    int low = 0, high = arr.size() -1;
    int floor = -1, ceil = -1;

    while(low <=high){
        int mid = low + (high - low)/2;
        if(arr[mid] == target){
            floor = ceil = mid;
            break;
        }
        else if(arr[mid] < target){
            floor = mid; // potential floor
            low = mid + 1; // search in the right half
        }
        else{
            ceil = mid; // potential ceil
            high = mid - 1;
        }
    }
    return {floor, ceil};
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)    arr.emplace_back(ip);
    int target = arr.back();
    arr.pop_back();

    pair<int, int> ans = floorAndCeil(arr, target);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}