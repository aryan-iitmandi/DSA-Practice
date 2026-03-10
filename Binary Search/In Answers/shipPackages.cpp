#include<bits/stdc++.h>
using namespace std;

int daysUsedWithCapacity(vector<int> &arr,int capacity){
    int fillShip = 0, dayUsed = 1;
    for(auto currentPacket: arr){
        if(fillShip + currentPacket > capacity){
            dayUsed++;
            fillShip = currentPacket;
        }
        else{
            fillShip += currentPacket;
        }
    }
    // cout << "Days used: " << dayUsed << endl;
    return dayUsed;
}

int shipPackages(vector<int> &weights, int daysLimit){
    int sumOfWeights = 0;
    for(auto it: weights)   sumOfWeights += it;

    int low = *max_element(weights.begin(), weights.end());
    int high = sumOfWeights;

    while(low < high){
        int mid = low + (high - low)/2;
        // cout << "low: " << low << " mid: " << mid << " high: " << high << endl;
        
        if(daysUsedWithCapacity(weights, mid) <= daysLimit)     high = mid;
        else    low = mid + 1;
    }
    return low;
}

int main(){
    vector<int> weights;
    int ip;
    while(cin >> ip)    weights.emplace_back(ip);
    int daysLimit = weights.back();
    weights.pop_back();

    cout << shipPackages(weights, daysLimit);
    return 0;
}