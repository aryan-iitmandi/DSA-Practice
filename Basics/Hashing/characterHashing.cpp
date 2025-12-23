#include<bits/stdc++.h>
using namespace std;

void charHash(const string &str, int q){
    // for a-z = 26, index = ch - 'a'
    // for A-Z = 26, index = ch - 'A'
    // ASCII = 256, index = ch
    vector<int> hash(256, 0);
    for(auto it: str){
        hash[it]++;
    }

    while(q--){
        char ch;
        cin >> ch;
        cout << ch << ":" << hash[ch] << " ";
    }
}

void charHashMap(const string &str, int q){
    map<char, int> hashmp;

    for(char ch: str){
        hashmp[ch]++;
    }

    while(q--){
        char ch;
        cin >> ch;
        cout << ch << ":" << hashmp[ch] << " ";
    }
}

void charHashUnorderedMap(const string &str, int q){
    unordered_map<char, int> hashump;

    for(char ch: str){
        hashump[ch]++;
    }

    while(q--){
        char ch;
        cin >> ch;
        cout << ch << ":" << hashump[ch] << " ";
    }
}

int main(){
    string str;
    cin >> str;

    int query;
    cin >> query;
    // charHash(str, query);
    // charHashMap(str, query);
    charHashUnorderedMap(str, query);
    return 0;
}