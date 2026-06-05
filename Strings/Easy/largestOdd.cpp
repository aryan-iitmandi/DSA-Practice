#include<bits/stdc++.h>
using namespace std;

string largestOdd(string &s){
    int end = -1;
    for(int i=s.size() -1; i>=0; i--){
        if((s[i] - '0') %2 == 1){
            end = i;
            break;
        }
    }

    int start = 0;
    while(start < end && s[start] == '0')   start++;

    return s.substr(start, end-start+1);
}

int main(){
    string num;
    cin >> num;

    string result = largestOdd(num);
    cout << result;

    return 0;
}