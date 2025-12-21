#include<bits/stdc++.h>
using namespace std;

// Time Complixity: O(sqrt(n))
// Space Complixity: O(number of divisor of n)
void divisor(int n){
    vector<int> res;
    for(int i=1; i*i<=n; i++){
        if((n%i) == 0){
            res.emplace_back(i);
            if((n/i) != i)  res.emplace_back((n/i));
        }
    }
    sort(res.begin(), res.end());
    for(auto it : res)  cout << it << "\n";
}

int main(){
    int n;
    cin >> n;
    divisor(n);
    return 0;
}