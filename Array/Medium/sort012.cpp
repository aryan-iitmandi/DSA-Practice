#include<bits/stdc++.h>
using namespace std;

void sortZeroOneTwo0(vector<int> &arr){
    int count0 = 0, count1 = 0, count2 = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == 0)  count0++;
        if(arr[i] == 1)  count1++;
        if(arr[i] == 2)  count2++;
    }
    int index = 0;
    while(count0--) arr[index++] = 0;
    while(count1--) arr[index++] = 1;
    while(count2--) arr[index++] = 2;
}

void sortZeroOneTwo1(vector<int> &arr){
    int low = 0, mid = 0, high = arr.size()-1;
    while(mid <= high){

        if(arr[mid] == 0){
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }

        else if(arr[mid] == 1)   mid++;

        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main(){
    vector<int> arr;
    int ip;

    while(cin >> ip)    arr.emplace_back(ip);

    // sortZeroOneTwo0(arr);
    sortZeroOneTwo1(arr);
    for(auto it: arr)   cout << it << " ";
    return 0;
}