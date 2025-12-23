#include<bits/stdc++.h>
using namespace std;

void countMinMaxfreq(const vector<int> &arr){
    unordered_map<int, int> hashmap;

    for(auto it: arr){
        hashmap[it]++;
    }

    int maxElement = INT_MIN, minElement = INT_MAX;
    int maxFreq = INT_MIN, minFreq = INT_MAX;

    for(auto it: hashmap){
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
    cout << "Max freq is " << maxFreq << " of element " << maxElement << endl;
    cout << "Min freq is " << minFreq << " of element " << minElement << endl;
}

int main(){
    int size;
    cin >> size;

    vector<int> arr(size);
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    countMinMaxfreq(arr);
    return 0;
}