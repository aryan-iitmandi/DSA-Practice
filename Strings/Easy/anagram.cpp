#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t){
    if(s.size() != t.size())    return false;

    int freq[256] = {0};
    for(char ch: s) freq[ch]++;
    for(char ch: t){
        freq[ch]--;
        if(freq[ch] < 0)    return false;
    }
    return true;
}

int main(){
    string s, t;
    cin >> s >> t;

    cout << isAnagram(s, t);
    return 0;
}