#include<bits/stdc++.h>
using namespace std;

int singleNumInArray(vector<int> &arr){
    int result = 0;
    for(auto it: arr)   result ^= it;
    return result;
}

int main(){
    vector<int> arr = {4, 6, 12, 9, 12, 4, 9};

    cout << singleNumInArray(arr);
    return 0;
}