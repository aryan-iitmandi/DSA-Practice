#include<bits/stdc++.h>
using namespace std;

// time: O(m+n)
// space: O(1)
void mergeSortedArrays(vector<int> &arr1, int m, vector<int> &arr2, int n){
    int i = m-1;
    int j = n-1;
    int k = m+n-1;

    while(j >= 0){
        if(i >=0 && arr1[i] > arr2[j]){
            arr1[k] = arr1[i];
            i--;
        }
        else{
            arr1[k] = arr2[j];
            j--;
        }
        k--;
    }
}

int main() {
    vector<int> arr1, arr2;
    string line;

    // Read first array
    if (getline(cin, line)) {
        stringstream ss(line);
        int x;
        while (ss >> x) arr1.push_back(x);
    }

    // Read second array
    if (getline(cin, line)) {
        stringstream ss(line);
        int x;
        while (ss >> x) arr2.push_back(x);
    }

    int n = arr2.size();
    int m = arr1.size() - n; // valid elements in nums1

    mergeSortedArrays(arr1, m, arr2, n);

    // Print merged nums1
    for (int x : arr1) {
        cout << x << " ";
    }

    return 0;
}
