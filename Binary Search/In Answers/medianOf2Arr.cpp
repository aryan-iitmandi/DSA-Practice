#include<bits/stdc++.h>
using namespace std;

double medianOf2Arr(vector<int> &arr1, vector<int> &arr2){
    int n = arr1.size(), m = arr2.size();
    if(n > m)  return medianOf2Arr(arr2, arr1);

    int low = 0, high = n;
    while(low <= high){
        int cut1 = low + (high - low)/2;
        int cut2 = (n + m + 1)/2 - cut1;

        int left1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int right1 = cut1 == n ? INT_MAX : arr1[cut1];
        int right2 = cut2 == m ? INT_MAX : arr2[cut2];

        if(left1 <= right2 && left2 <= right1){
            if((n+m)%2 == 0)    return (max(left1, left2) + min(right1, right2)) / 2.0;
            else    return max(left1, left2);
        }
        else if(left1 > right2)    high = cut1 - 1;
        else    low = cut1 + 1;
    }
    return 0.0;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n), arr2(m);
    for(int i=0; i<n; i++)     cin >> arr1[i];
    for(int i=0; i<m; i++)     cin >> arr2[i];

    cout << medianOf2Arr(arr1, arr2);
    return 0;
}