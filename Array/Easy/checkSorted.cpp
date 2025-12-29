#include<bits/stdc++.h>
using namespace std;

bool checkSorted(const vector<int> &arr){
    int n = arr.size();

    for(int i=1; i<=n-1; i++){
        if(arr[i] < arr[i-1])   return false;
    }
    return true;
}

void removeDuplicates(vector<int> &arr){
    if(!checkSorted(arr)) return;
    int n = arr.size();
    if(n == 0)  return;

    int i = 0;
    for(int j=1; j<=n-1; j++){
        if(arr[j] != arr[i]){
            i++;
            arr[i] = arr[j];
        }
    }
    for(int k=0; k<=i; k++)   cout << arr[k] << " ";
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip){
        arr.emplace_back(ip);
    }
    cout << "Is Array Sorted? " << checkSorted(arr) << endl;
    removeDuplicates(arr);
    return 0;
}