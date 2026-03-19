#include<bits/stdc++.h>
using namespace std;

int firstOneInRow(vector<int> &row){
    int low = 0, high = row.size()-1;
    int ans = -1;

    while(low <= high){
        int mid = low + (high-low)/2;
        
        if(row[mid] == 1){
            ans = mid;
            high = mid-1;
        }
        else    low = mid+1;
    }
    return ans;
}

// binary search 
// time: O(nlogm)
// space: O(1)
int maximum1InRow(vector<vector<int>> &arr, int n, int m){
    int maxOne = 0;
    int index = -1;

    for(int i=0; i<n; i++){
        int firstOne = firstOneInRow(arr[i]);
        if(firstOne != -1){
            int nofOnes = m-firstOne;

            if(nofOnes > maxOne){
                maxOne = nofOnes;
                index = i;
            }
        }
    }
    return index;
}

// optimal
// time: O(n+m)
int maximum1InRowOptimal(vector<vector<int>> &arr, int n, int m){
    int row = 0, col = m - 1;
    int index = -1;

    while(row < n && col >=0){
        if(arr[row][col] == 1){
            index = row;
            col--;
        }
        else   row++;
    }
    return index;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    // cout << maximum1InRow(arr, n, m) << endl;
    cout << maximum1InRowOptimal(arr, n, m) << endl;
    return 0;
}