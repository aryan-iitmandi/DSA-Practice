#include<bits/stdc++.h>
using namespace std;

bool checkPalindromeRecursion(const string &str, int l, int r){
    if(l >= r) return true;
    if(str[l] != str[r]) return false;
    return checkPalindromeRecursion(str, l+1, r-1);
}

bool checkPalindrome(const string &str){
    int n = str.length();
    int l = 0;
    int r = n-1;

    while(l < r){
        if(str[l++] != str[r--])    return false;
        // l++;
        // r--;
    }
    return true;
}

int main(){
    string str;
    cin >> str;
    cout << checkPalindromeRecursion(str, 0, str.length()-1);
    cout << checkPalindrome(str);
    return 0;
}