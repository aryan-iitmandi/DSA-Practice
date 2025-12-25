#include<bits/stdc++.h>
using namespace std;

// select last element as pivot, rearrange array according to pivot, return index of pivot
int partition(vector<int> &arr, int low, int high){
    int pivot = arr[high];
    int ptr = low - 1;

    for(int j=low; j<=high-1; j++){
        if(arr[j] <= pivot){
            ptr++;
            swap(arr[ptr], arr[j]);
        }
    }
    swap(arr[ptr+1], arr[high]);
    return ptr+1;
}

// Time Complixity: best O(nlogn), average O(nlogn), worst O(n^2)
// Space Complixity: O(nlogn) recursive stack
// in-place
void quickSort(vector<int> &arr, int low, int high){
    if(low < high){
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

int main(){
    vector<int> arr;
    
    int ip;
    while(cin >> ip){
        arr.push_back(ip);
    }

    quickSort(arr, 0, arr.size()-1);

    for(auto i: arr){
        cout << i << " ";
    }
    return 0;
}