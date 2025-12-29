#include<bits/stdc++.h>
using namespace std;

// Time Complixity: O(n^2), best case where ip is nearly/completely sorted it takes O(n)
// Spce Complixity: O(1)
// stable
// in-place
void bubbleSort(vector<int> &arr){
    int n = arr.size();

    for(int i=n-2; i>=0; i--){
        bool swapFlag = false;
        for(int j=0; j<=i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapFlag = true;
            }
        }
        if(!swapFlag)    break;
    }
}

void bubbleSortRecursive(vector<int> &arr, int n){
    if(n == 1)  return;
    
    bool swapFlag = false;
    for(int j=0; j<=n-2; j++){
        if(arr[j] > arr[j+1]){
            swap(arr[j], arr[j+1]);
            swapFlag = true;
        }
    }
    if(!swapFlag) return;
    bubbleSortRecursive(arr, n-1);
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip){
        arr.push_back(ip);
    }

    // bubbleSort(arr);
    bubbleSortRecursive(arr, arr.size());
    for(auto i: arr){
        cout << i << " ";
    }
    return 0;
}