#include<bits/stdc++.h>
using namespace std;

int searchInRotatedSortedArray(vector<int> &arr, int target){
    int low = 0, high = arr.size() -1;
    
    while(low <= high){
        int mid = low + (high - low)/2;
        // cout << "low: " << low << " mid: " << mid << " high: " << high << endl;
        if(arr[mid] == target)   return mid;

        // if all three elements are equal, we cannot determine which half is sorted, so we can just skip the duplicates
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low++;
            high--;
            continue;
        }

        // check if left half is sorted
        if(arr[low] <= arr[mid]){
            // check if target lies in the left half
            if(arr[low] <= target && target < arr[mid])    high = mid - 1;
            else    low = mid + 1;
        }

        // right half is sorted
        else{
            // check if target lies in the right half
            if(arr[mid] < target && target <= arr[high])   low = mid + 1;
            else    high = mid - 1;
        }
    }
    return -1; 
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)   arr.emplace_back(ip);
    int target = arr.back();
    arr.pop_back();

    cout << searchInRotatedSortedArray(arr, target);
    return 0;
}