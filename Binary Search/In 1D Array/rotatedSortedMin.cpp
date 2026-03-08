#include<bits/stdc++.h>
using namespace std;

pair<int, int> minimumInRotSot(vector<int> &arr){
    int low = 0, high = arr.size() -1;
    
    while(low < high){
        int mid = low + (high - low) / 2;
        // cout << "low: " << low << " mid: " << mid << " high: " << high << endl;

        if(arr[mid] > arr[high]){
            low = mid + 1;
        }
        else{
            high = mid;
        }
    }
    return {arr[low], low};
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)    arr.emplace_back(ip);

    pair<int, int> ans = minimumInRotSot(arr);
    cout << "Minimum element in Rotated array: " << ans.first << endl;
    cout << "Number of times sorted array rotated: " << ans.second << endl;
    return 0;
}