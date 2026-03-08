#include<bits/stdc++.h>
using namespace std;

// returns floor (root(n))
int sqrt(int &n){
    int low = 1, high = n;
    int ans = 0;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(mid*mid <= n){
            ans = mid;
            low = mid + 1;
        }    
        else    high = mid -1;
    }
    return ans;
}

int nthroot(int n, int m){
    int low = 1, high = m;
    int ans = 0;

    while(low <= high){

        int mid = low + (high - low)/2;

        long long ans = 1;
        for(int i=0; i<n; i++){
            ans *= mid;
            if(ans > m) break;
        }

        if(ans == m)  return mid;
        if(ans < n)     low = mid + 1;
        else    high = mid -1;
    }
    return -1;
}

int main(){
    int n, m;
    cin >> n >> m;

    // cout << sqrt(num);
    cout << nthroot(n, m);
    return 0;
}