#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(const string &str, int l, int r){
    if(l >= r) return true;
    if(str[l] != str[r]) return false;
    return checkPalindrome(str, l+1, r-1);
}

int main(){
    string str;
    cin >> str;
    cout << checkPalindrome(str, 0, str.length()-1);
    return 0;
}