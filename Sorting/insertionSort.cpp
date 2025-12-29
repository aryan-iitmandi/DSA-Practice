#include<bits/stdc++.h>
using namespace std;

// Time Complixity: O(n^2), best case where ip is nearly/completely sorted it takes O(n)
// Spce Complixity: O(1)
// stable
// in-place
void insertionSort(vector<int> &arr){
    int n = arr.size();

    for(int i=1; i<=n-1; i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void insertionsortRecursive(vector<int> &arr, int start){
    int n = arr.size();
    if(start == n)  return;
    
    int key = arr[start];
    int j = start-1;

    while(j>=0 && arr[j] > key){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;

    insertionsortRecursive(arr, start+1);
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip){
        arr.push_back(ip);
    }

    // insertionSort(arr);
    insertionsortRecursive(arr, 0);
    for(auto i: arr){
        cout << i << " ";
    }
    return 0;
}