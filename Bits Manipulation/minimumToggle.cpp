#include<bits/stdc++.h>
using namespace std;

int minimumToggle(int start, int goal){
    int diffBits = start ^ goal;
    
    // count nof set bits 
    int count = 0;
    while(diffBits > 0){
        diffBits &= (diffBits-1);
        count++;
    }
    return count;
}

int main(){
    int start, goal;
    cin >> start >> goal;

    cout << minimumToggle(start, goal);
    return 0;
}