#include<bits/stdc++.h>
using namespace std;

// Time Complexity	O(n)
// Space Complexity	O(1)
void findElements(const vector<int> &arr){
    int n = arr.size();
    int min = INT_MAX, secondMin = INT_MAX;
    int max = INT_MIN, secondMax = INT_MIN;

    for(int i=0; i<=n-1; i++){
        if(arr[i] < min){
            secondMin = min;
            min = arr[i];
        }
        else if(arr[i] < secondMin && arr[i] > min)
            secondMin = arr[i];
    }
    for(int i=0; i<=n-1; i++){
        if(arr[i] > max){
            secondMax = max;
            max = arr[i];
        }
        else if(arr[i] > secondMax && arr[i] < max)
            secondMax = arr[i];
    }
    cout << "Minimum: " << min << endl;
    cout << "Second Minimum: " << secondMin << endl;
    cout << "Second Maximun: " << secondMax << endl;
    cout << "Maximum: " << max << endl;
}

int main(){
    vector<int> arr;
    int ip;

    while(cin >> ip){
        arr.push_back(ip);
    }

    findElements(arr);
    return 0;
}