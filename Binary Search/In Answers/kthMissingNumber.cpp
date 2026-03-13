#include<bits/stdc++.h>
using namespace std;

int kthMissing(vector<int> &arr, int k){
    int low = 0, high = arr.size() -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        // cout << "low: " << low << " mid: " << mid << " high: " << high << endl;

        int missing = arr[mid] - (mid + 1);
        if(missing < k)     low = mid+1;
        else    high = mid - 1;
    }
    return k + low;
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)    arr.emplace_back(ip);
    int k = arr.back();
    arr.pop_back();

    cout << kthMissing(arr, k);
    return 0;
}