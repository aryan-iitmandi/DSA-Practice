#include<bits/stdc++.h>
using namespace std;

// merge two sorted array
void merge(vector<int> &arr, int left, int mid, int right){
    vector<int> temp;
    int i = left, j = mid+1;

    // compare element of both array and push the smaller one in temp
    while (i <= mid && j <= right)
    {
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    // after comparision and insertion, push remaining element of left array
    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
    // after comparision and insertion, push remaining element of right array
    while(j <= right){
        temp.push_back(arr[j]);
        j++;
    }
    // paste temp array back to arr
    for(int k=0; k<temp.size(); k++){
        arr[left + k] = temp[k];
    }
}

// Time Complixity: O(nlogn)
// Spce Complixity: O(n)
// stable
void mergeSort(vector<int> &arr, int left, int right){
    if(left >= right)   return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

int main(){
    vector<int> arr;
    
    int ip;
    while(cin >> ip){
        arr.push_back(ip);
    }

    mergeSort(arr, 0, arr.size()-1);

    for(auto i: arr){
        cout << i << " ";
    }
    return 0;
}