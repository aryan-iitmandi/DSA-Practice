#include<bits/stdc++.h>
using namespace std;

// optimal
// time : O(n)
// space: O(1)
vector<int> subArrWithXOR(vector<int> &arr, int k){
    vector<int> ans;
    int prefixXOR = 0;
    unordered_set<int> seenXORs;
    seenXORs.insert(0); // to handle the case when prefixXOR itself is equal to k
    
    for(int num: arr){
        prefixXOR ^= num;
        int requiredXOR = prefixXOR ^ k; // to find the required prefixXOR that would give us k when XORed with current prefixXOR

        if(seenXORs.count(requiredXOR)){
            ans.push_back(num);
        }
        seenXORs.insert(prefixXOR);
    }
    return ans;
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)    arr.emplace_back(ip);

    int k;
    k = arr.back();
    arr.pop_back();

    vector<int> ans = subArrWithXOR(arr, k);
    for(auto it: ans)    cout << it << " ";
    return 0;
}