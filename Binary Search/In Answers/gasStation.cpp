#include<bits/stdc++.h>
using namespace std;

int nofGasStationReq(vector<int> &stations, long double dist){
    int count = 0;

    for(int i=1; i<stations.size(); i++){
        int stationBetGap = (stations[i] - stations[i-1]) / dist;
        if((stations[i] - stations[i-1]) == stationBetGap*dist)     stationBetGap--;

        count += stationBetGap;
    }
    return count;
}

long double gasStation(vector<int> &stations, int k){
    long double low = 0, high = 0;
    for(int i=1; i<stations.size(); i++)     high = max(high, (long double)stations[i] - stations[i-1]);

    while(high - low >= 1e-6){
        double mid = low + (high - low)/2;

        if(nofGasStationReq(stations, mid) > k)     low = mid;
        else        high = mid;
    }
    return high;
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)    arr.emplace_back(ip);
    int k = arr.back();
    arr.pop_back();

    cout << gasStation(arr, k);
    return 0;
}