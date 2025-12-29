#include<bits/stdc++.h>
using namespace std;

// Time Complixity: O((n+m) log(n+m))
// Space Complixity: O(n+m)
vector<int> unionOf2Array(vector<int> &arr1, vector<int> &arr2){
    map<int, int> freq;
    vector<int> result;

    for(auto it: arr1)  freq[it]++;
    for(auto it: arr2)  freq[it]++;

    for(auto &it: freq)     result.push_back(it.first);

    return result;
}

vector<int> unionOptimal(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size(), m = arr2.size();
    int i = 0, j = 0;
    vector<int> result;

    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            if (result.empty() || result.back() != arr1[i])
                result.push_back(arr1[i]);
            i++;
        }
        else if (arr2[j] < arr1[i]) {
            if (result.empty() || result.back() != arr2[j])
                result.push_back(arr2[j]);
            j++;
        }
        else { // equal
            if (result.empty() || result.back() != arr1[i])
                result.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    while (i < n) {
        if (result.empty() || result.back() != arr1[i])
            result.push_back(arr1[i]);
        i++;
    }

    while (j < m) {
        if (result.empty() || result.back() != arr2[j])
            result.push_back(arr2[j]);
        j++;
    }

    return result;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr1(n);
    for(int i=0; i<n; i++){
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    vector<int> arr2(m);
    for(int i=0; i<m; i++){
        cin >> arr2[i];
    }

    // vector<int> result = unionOf2Array(arr1, arr2);
    vector<int> result = unionOptimal(arr1, arr2);
    for (int it : result) {
        cout << it << " ";
    }

    return 0;
}