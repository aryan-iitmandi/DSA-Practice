#include<bits/stdc++.h>
using namespace std;

void hashing(const vector<int> &arr, int q){
    // const int MAX = 100000;
    int maxElement = *max_element(arr.begin(), arr.end());
    vector<int> hash(maxElement+1, 0);

    for(auto it: arr){
        hash[it]++;
    }

    while(q--){
        int num;
        cin >> num;
        cout << num << ":" << hash[num] << " ";
    }

}

void hashUsingMap(const vector<int> &arr, int q){
    map<int, int> hashmp;

    for(int it: arr){
        hashmp[it]++;
    }

    while(q--){
        int num;
        cin >> num;
        cout << num << ":" << hashmp[num] << " ";
    }
}

void hashUsingUnorderedMap(const vector<int> &arr, int q){
    unordered_map<int, int> hashump;

    for(int it: arr){
        hashump[it]++;
    }

    while(q--){
        int num;
        cin >> num;
        cout << num << ":" << hashump[num] << " ";
    }
}

int main(){
    int size;
    cin >> size;

    vector<int> arr(size);
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    int query;
    cin >> query;
    // hashing(arr, query);
    // hashUsingMap(arr, query);
    hashUsingUnorderedMap(arr, query);

    return 0;
}











// int main(){
//     int size;
//     cin >> size;
//     int arr[size];
//     cout << "Data array of size " << size << " is: ";
//     for(int i=0; i<size; i++){
//         cin >> arr[i];
//         cout << arr [i] << " ";
//     }
//     cout << endl;

//     // Hash Array
//     const int MAX = 100000;
//     vector<int> hash(MAX+1, 0);

//     // Precompute Freq
//     for(int i=0; i<size; i++){
//         hash[arr[i]] += 1;
//     }

//     int query;
//     cin >> query;
//     while(query--){
//         int num;
//         cin >> num;
//         cout << "Freq of: " << num << " is " << hash[num] << endl;
//     }
//     return 0;
// }