#include<bits/stdc++.h>
using namespace std;

bool isRotating(string s, string goal){
    if(s.size() != goal.size())     return false;
    
    string doubleS = s+s;
    return doubleS.find(goal) != string::npos;
}

int main(){
    string s, goal;
    cin >> s >> goal;

    cout << isRotating(s, goal);
    return 0;
}