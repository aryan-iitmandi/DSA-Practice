#include<bits/stdc++.h>
using namespace std;

// Time: O(n! * n)
// Space: O(n!)
vector<int> nextPermutationBrute(vector<int> &arr){
    vector<int> original = arr;
    vector<vector<int>> allPerm;
    sort(arr.begin(), arr.end());
    do{
        allPerm.push_back(arr);
    }while(next_permutation(arr.begin(), arr.end()));

    for(int i=0; i<allPerm.size(); i++){
        if(allPerm[i] == arr){
            if(i == allPerm.size() - 1)     return allPerm[0];
            else    return allPerm[i+1];
        }
    }
    return original;
}

// Time: O(n)
// Space: O(1)
void nextPermutation(vector<int> &arr){
    int n = arr.size();
    int i = n-2;

    while(i >=0 && arr[i] >= arr[i+1])  i--;

    if(i >= 0){
        int j = n - 1;
        while(arr[j] <= arr[i])     j--;
        swap(arr[i], arr[j]);
    }
    reverse(arr.begin()+i+1, arr.end());
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)
        arr.emplace_back(ip);

    // arr = nextPermutationBrute(arr);
    nextPermutation(arr);
    for (int x : arr)
        cout << x << " ";    
    
    return 0;
}