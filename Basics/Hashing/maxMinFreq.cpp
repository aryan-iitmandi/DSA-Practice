#include <bits/stdc++.h>
using namespace std;

void countMinMaxFrequency(const vector<int>& arr){
    unordered_map<int, int> freq;

    // Step 1: Count frequencies
    for(int x : arr){
        freq[x]++;
    }

    int maxFreq = INT_MIN, minFreq = INT_MAX;
    int maxElement = -1, minElement = -1;

    // Step 2: Find min and max frequency elements
    for(auto &it : freq){
        int element = it.first;
        int count = it.second;

        if(count > maxFreq){
            maxFreq = count;
            maxElement = element;
        }

        if(count < minFreq){
            minFreq = count;
            minElement = element;
        }
    }

    cout << maxElement << " " << minElement << endl;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    countMinMaxFrequency(arr);

    return 0;
}
