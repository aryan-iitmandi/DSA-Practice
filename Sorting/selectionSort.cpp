#include<bits/stdc++.h>
using namespace std;

// Time Complixity: O(n^2) time in the best, average, and worst cases. No.of comparisions = n(n-1)/2
// Spce Complixity: O(1)
// in-place
void selectionSort(vector<int> &arr){
    int n = arr.size();

    for(int i=0; i<n-1; i++){

        // Find index of minimum element
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        // Swap min index element with start of unsorted sub-array
        swap(arr[i], arr[minIndex]);
    }
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip){
        arr.push_back(ip);
    }

    selectionSort(arr);

    for(auto i: arr){
        cout << i << " ";
    }
    return 0;
}