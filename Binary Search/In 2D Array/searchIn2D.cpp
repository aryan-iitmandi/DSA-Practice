#include<bits/stdc++.h>
using namespace std;

bool seachIn2D(vector<vector<int>> &arr, int n, int m, int target){
    int low = 0, high = n*m-1;

    while(low <= high){
        int mid = low + (high-low)/2;
        int midElement = arr[mid/m][mid%m];

        if(midElement == target)    return true;
        else if(midElement < target)   low = mid+1;
        else    high = mid-1;
    }
    return false;
}

// time: O(log(n*m))
bool searchIn2DOptimal(vector<vector<int>> &arr, int n, int m, int target){
    int row = 0, col = m-1;

    while(row < n && col >= 0){
        if(arr[row][col] == target)    return true;
        else if(arr[row][col] < target)   row++;
        else    col--;
    }
    return false;
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
    int target;
    cin >> target;

    cout << seachIn2D(arr, n, m, target) << endl;
    return 0;
}