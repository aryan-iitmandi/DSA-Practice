#include<bits/stdc++.h>
using namespace std;

// brute force: O(n^2)
int maxProduct(vector<int> &arr){
    int maxProd = INT_MIN;

    for(int i=0; i<arr.size(); i++){
        int prod = 1;
        for(int j=i; j<arr.size(); j++){
            prod *= arr[j];
            maxProd = max(maxProd, prod);
        }
    }
    return maxProd;
}

// optimal 1: O(n)
int maxProductOptimal(vector<int> &arr){
    int prefixProd = 1, suffixProd = 1, maxProd = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        prefixProd *= arr[i];
        suffixProd *= arr[arr.size() - 1 - i];

        maxProd = max(maxProd, max(prefixProd, suffixProd));

        if(prefixProd == 0)   prefixProd = 1;
        if(suffixProd == 0)   suffixProd = 1;
    }
    return maxProd;
}

// optimal 2: O(n)
int maxProductOptimal2(vector<int> &arr){
    int maxProd = arr[0], minProd = arr[0], result = arr[0];
    for(int i=1; i<arr.size(); i++){
        if(arr[i] < 0)   swap(maxProd, minProd);

        maxProd = max(arr[i], maxProd * arr[i]);
        minProd = min(arr[i], minProd * arr[i]);

        result = max(result, maxProd);
    }
    return result;
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)    arr.emplace_back(ip);

    // cout << maxProduct(arr) << endl;
    // cout << maxProductOptimal(arr) << endl;
    cout << maxProductOptimal2(arr) << endl;
    return 0;
}