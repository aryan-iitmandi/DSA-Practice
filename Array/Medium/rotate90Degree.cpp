#include<bits/stdc++.h>
using namespace std;

// time: O(n*n)
// space: O(1)
void rotate90Degree(vector<vector<int>> &matrix){
    int n = matrix.size();
    if(n == 0) return;

    // transpose the matrix
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // reverse each row
    for(int i=0; i<n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }
    
    rotate90Degree(matrix);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}