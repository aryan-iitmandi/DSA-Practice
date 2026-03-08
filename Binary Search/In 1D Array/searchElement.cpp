#include<bits/stdc++.h>
using namespace std;

// iterative approach
// time : O(log n)
// space: O(1)
int binarySearch(vector<int> &arr, int target){
    int low = 0, high = arr.size() -1;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(arr[mid] == target)    return mid;
        else if(arr[mid] < target)    low = mid + 1;
        else   high = mid - 1;
    }
    return -1;
}

// recursive approach
// time : O(log n)
// space: O(log n) due to recursive stack space
int binarySearchRec(vector<int> &arr, int low, int high, int target){
    if(low > high)    return -1;

    int mid = low + (high - low)/2;
    if(arr[mid] == target)    return mid;
    else if(arr[mid] < target)    return binarySearchRec(arr, mid + 1, high, target);
    else   return binarySearchRec(arr, low, mid - 1, target);
}

// lower bound
int lowerBound(vector<int> &arr, int target){
    int low = 0, high = arr.size() -1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] >= target){
            ans = mid;
            high = mid-1;
        }
        else    low = mid+1;
    }
    return ans;
}

// upper bound
int upperBound(vector<int> &arr, int target){
    int low = 0, high = arr.size()-1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] > target){
            ans = mid;
            high = mid -1;
        }
        else    low = mid+1;
    }
    return ans;
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)    arr.emplace_back(ip);
    int target = arr.back();
    arr.pop_back();

    cout << binarySearch(arr, target) << endl;
    // cout << binarySearchRec(arr, 0, arr.size() - 1, target);

    cout << lowerBound(arr, target) << endl;
    cout << upperBound(arr, target) << endl;
    
    // // predefined lower bound function
    // auto it = lower_bound(arr.begin(), arr.end(), target);
    // if(it != arr.end())    cout << (it - arr.begin()) << endl;
    // else    cout << -1 << endl;
    // // predefined upper bound function
    // auto it2 = upper_bound(arr.begin(), arr.end(), target);
    // if(it2 != arr.end())    cout << (it2 - arr.begin()) << endl;
    // else    cout << -1 << endl;

    return 0;
}