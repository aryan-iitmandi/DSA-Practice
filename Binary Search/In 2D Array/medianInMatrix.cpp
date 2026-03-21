#include<bits/stdc++.h>
using namespace std;

int medianInMatrix(vector<vector<int>> &arr, int n, int m){
    int low = arr[0][0];
    int high = arr[n-1][m-1];

    while(low <= high){
        int mid = low + (high-low)/2;
        int count = 0;

        for(int i=0; i<n; i++){
            count += upper_bound(arr[i].begin(), arr[i].end(), mid) - arr[i].begin();
        }

        if(count <= (n*m)/2)   low = mid+1;
        else    high = mid-1;
    }
    return low;
}

// row wise sorted matrix
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    cout << medianInMatrix(arr, n, m) << endl;
    return 0;
}