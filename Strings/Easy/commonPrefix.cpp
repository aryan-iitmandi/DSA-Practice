#include<bits/stdc++.h>
using namespace std;

// time: O(NlogN * M)
string commonPrefix(vector<string> &strs){
    sort(strs.begin(), strs.end());
    string first = strs.front();
    string last = strs.back();

    int i=0;
    while(i<first.size() && i<last.size() && first[i] == last[i])   i++;

    return first.substr(0, i);
}

// time: O(N*M)
string commonPrefixOptimal(vector<string> &strs){
    for(int i=0; i<strs.front().size(); i++){
        char ch = strs[0][i];

        for(int j=1; j<strs.size(); j++){
            if(strs[j][i] != ch || i>=strs[j].size())    return strs[0].substr(0, i);
        }
    }
    return strs[0];
}

int main(){
    int n;
    cin >> n;
    vector<string> strs(n);
    for(int i=0; i<n; i++)  cin >> strs[i];

    cout << commonPrefixOptimal(strs);
    return 0;
}