#include <bits/stdc++.h>
using namespace std;

string removeOutermostParanthesis(string s){
    string result = "";
    int level = 0;

    for(char c : s){
        if(c == '('){
            if(level > 0)   result += c;
            level++;
        }

        else if(c == ')'){
            level--;
            if(level > 0)   result += c; 
        }
    }
    return result;
}

int main(){
    string s;
    cin >> s;

    string result = removeOutermostParanthesis(s);
    cout << result;

    return 0;
}