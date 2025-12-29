#include<bits/stdc++.h>
using namespace std;

int maxConsecutive1(vector<int> &arr){
    int n = arr.size();
    int count = 0, maxCount = 0;

    for(int it: arr){
        if(it == 1){
            count++;
            maxCount = max(count, maxCount);
        }
        else    count = 0;
    }
    return maxCount;
}

int main(){
    vector<int> arr;
    int ip; // start arr from 0
    while (cin >> ip){
        arr. emplace_back(ip);  
    }

    cout << maxConsecutive1(arr);
    
    return 0;
}