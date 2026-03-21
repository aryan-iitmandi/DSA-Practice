#include<bits/stdc++.h>
using namespace std;

int peakElement(vector<vector<int>> &arr, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int up = (i-1 >= 0) ? arr[i-1][j] : INT_MIN;
            int down = (i+1 < n) ? arr[i+1][j] : INT_MIN;
            int left = (j-1 >= 0) ? arr[i][j-1] : INT_MIN;
            int right = (j+1 < m) ? arr[i][j+1] : INT_MIN;

            if(arr[i][j] > up && arr[i][j] > down && arr[i][j] > left && arr[i][j] > right){
                return arr[i][j];
            }
        }
    }
    return -1;
}

int naxElementInColumn(vector<vector<int>> &arr, int n, int col){
    int maxElement = arr[0][col];
    int index = 0;

    for(int i=1; i<n; i++){
        if(arr[i][col] > maxElement){
            maxElement = arr[i][col];
            index = i;
        }
    }
    return index;
}

int peakElementOptimal(vector<vector<int>> &arr, int n, int m){
    int low = 0, high = m-1;

    while(low <= high){
        int mid = low + (high-low)/2;
        int maxElementIndex = naxElementInColumn(arr, n, mid);
        int up = (maxElementIndex-1 >= 0) ? arr[maxElementIndex-1][mid] : INT_MIN;
        int down = (maxElementIndex+1 < n) ? arr[maxElementIndex+1][mid] : INT_MIN;
        int left = (mid-1 >= 0) ? arr[maxElementIndex][mid-1] : INT_MIN;
        int right = (mid+1 < m) ? arr[maxElementIndex][mid+1] : INT_MIN;

        if(arr[maxElementIndex][mid] > up && arr[maxElementIndex][mid] > down && arr[maxElementIndex][mid] > left && arr[maxElementIndex][mid] > right){
            return arr[maxElementIndex][mid];
        }
        else if(arr[maxElementIndex][mid] < right)   low = mid+1;
        else    high = mid-1;
    }
    return -1;
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

    // cout << peakElement(arr, n, m) << endl;
    cout << peakElementOptimal(arr, n, m) << endl;
    return 0;
}