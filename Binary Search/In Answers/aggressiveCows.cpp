#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr,int k, int dis){
    int cows = 1;
    int currentPos = arr[0];

    for(int i=1; i<arr.size(); i++){
        if(arr[i] - currentPos >= dis){
            cows++;
            currentPos = arr[i];
        }
        if(cows >= k)   return true;
    }
    return false;
}

int aggressiveCows(vector<int> &arr, int k){
    sort(arr.begin(), arr.end());

    int low = 1;
    int high = arr.back() - arr.front();
    int ans = 0;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(isPossible(arr, k, mid)){
            ans = mid;
            low = mid +1;
        }    
        else    high = mid - 1;
    }
    return ans;
}

int main(){
    vector<int> stalls;
    int ip;
    while(cin >> ip)    stalls.emplace_back(ip);
    int nofCows = stalls.back();
    stalls.pop_back();

    cout << aggressiveCows(stalls, nofCows);
    return 0;
}