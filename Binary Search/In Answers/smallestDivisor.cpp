#include<bits/stdc++.h>
using namespace std;

// time: O(n log m)
// space: O(1)
int smallestDivisor(vector<int> &arr, int limit){
    if(limit < arr.size())  return -1;

    int low = 1;
    int high = *max_element(arr.begin(), arr.end());

    while(low < high){
        int mid = low + (high - low)/2;
        int sum = 0;

        for(auto it: arr)   sum += ceil((double)it/mid);

        if(sum <= limit)      high = mid;
        else    low = mid +1;
    }
    return low;
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)    arr.emplace_back(ip);
    int limit = arr.back();
    arr.pop_back();

    cout << smallestDivisor(arr, limit);
    return 0;
}

// ceil(x/y) = (x + y - 1)/y  // this is better and safer version to calc ceil