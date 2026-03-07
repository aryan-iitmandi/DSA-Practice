#include<bits/stdc++.h>
using namespace std;

// time: O(log n)
// space: O(1)
pair<int, int> firstAndLast(vector<int> &arr, int target){
    int low = 0, high = arr.size() -1;
    int first = -1;

    // find first occurrence
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == target){
            first = mid; // potential first occurence
            high = mid - 1; // search in the left half
        }
        else if(arr[mid] < target)    low = mid + 1;
        else   high = mid - 1;
    }

    // find last occurrence
    low = 0, high = arr.size() -1;
    int last = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == target){
            last = mid; // potential last occurence
            low = mid + 1; // search in the right half
        }
        else if(arr[mid] < target)    low = mid + 1;
        else   high = mid - 1;
    }

    return {first, last};
}

int nofOccurrences(vector<int> &arr, int target){
    pair<int, int> firstLast = firstAndLast(arr, target);
    if(firstLast.first == -1)    return 0; // target not found
    return firstLast.second - firstLast.first + 1;
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)    arr.emplace_back(ip);
    int target = arr.back();
    arr.pop_back();

    pair<int, int> ans = firstAndLast(arr, target);
    cout << ans.first << " " << ans.second << endl;
    cout << nofOccurrences(arr, target) << endl;
    return 0;
}