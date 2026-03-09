#include<bits/stdc++.h>
using namespace std;

int totalHoursToEat(vector<int> &arr, int speed){
    int totalHours = 0;
    for(auto bananas: arr)      totalHours += ceil((double)bananas / speed);

    return totalHours;
}

// time: O(n log m) where n is the number of piles and m is the maximum number of bananas in a pile
// space: O(1)
int bananasPerHour(vector<int> &arr, int h){
    if(h < arr.size())    return -1;
    int low = 1, high = *max_element(arr.begin(), arr.end());

    while(low < high){
        int mid = low + (high - low)/2;
        
        if(totalHoursToEat(arr, mid) <= h)    high = mid;
        else    low = mid + 1;
    }
    return low;
}

int main(){
    vector<int> bananas;
    int ip;
    while(cin >> ip)    bananas.emplace_back(ip);
    int hours = bananas.back();
    bananas.pop_back();

    cout << bananasPerHour(bananas, hours) << endl;
    return 0;
}