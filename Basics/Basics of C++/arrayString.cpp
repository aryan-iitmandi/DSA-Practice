#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    getline(cin, str);
    str[0]=toupper(str[2]);
    str[3] = 'Z';
    cout<<str<<"\n";
    return 0;
}