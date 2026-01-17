#include<bits/stdc++.h>
using namespace std;

// Time: O(n^2)
// Space: O(n)
bool search(vector<int> &arr, int num){
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == num)   return true;
    }
    return false;
}
int longestConsecutive0(vector<int> &arr){
    int n = arr.size();
    if(n == 0)  return 0;

    int longest = 1;
    for(int i=0; i<n; i++){
        int x = arr[i];
        int count = 1;
        while(search(arr, x + 1)){
            x++;
            count++;
        }
        longest = max(count, longest);
    }
    return longest;
}

// Time: O(n)
// Space: O(n)
int longestConsecutive1(vector<int> &arr){
    if(arr.empty())     return 0;

    unordered_set<int> s;
    for(int it: arr)
        s.insert(it);
    
    int longest = 1;
    for(int it: arr){
        if(s.find(it - 1) == s.end()){
            int current = it;
            int count = 1;

            while(s.find(current + 1) != s.end()){
                count++;
                current++;
            }
            longest = max(longest, count);
        }
    }
    return longest;
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)
        arr.emplace_back(ip); 
    
    // cout << longestConsecutive0(arr);
    cout << longestConsecutive1(arr);
    return 0;
}