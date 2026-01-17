#include<bits/stdc++.h>
using namespace std;

// Time: O(m*m)
// Space: O(m+n)
void setZeroes(vector<vector<int>> &matrix){
    int m = matrix.size();
    if(m == 0) return;
    int n = matrix[0].size();
    // cout << m << " " << n << endl;
    vector<bool> zeroRow(m, false);
    vector<bool> zeroCol(n, false);
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == 0){
                zeroRow[i] = true;
                zeroCol[j] = true;
            }
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(zeroRow[i] || zeroCol[j]){
                matrix[i][j] = 0;
            }
        }
    }
}

// Time: O(m*n)
// Space: O(1)
void setZerosOptimal(vector<vector<int>> &matrix){
    int m = matrix.size();
    if(m == 0) return;
    int n = matrix[0].size();
    bool isFirstRowZero = false;
    bool isFirstColZero = false;

    // check first row is zero
    for(int i=0; i<m; i++){
        if(matrix[i][0] == 0){
            isFirstColZero = true;
            break;
        }
    }
    // check first col is zero
    for(int i=0; i<m; i++){
        if(matrix[0][i] == 0){
            isFirstRowZero = true;
            break;
        }
    }
    
    // mark zeros in row and col
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // set zeros based on marks
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }

    // set first col zeros
    if(isFirstColZero){
        for(int i=0; i<m; i++){
            matrix[i][0] = 0;
        }
    }
    // set first row zeros
    if(isFirstRowZero){
        for(int i=0; i<m; i++){
            matrix[0][i] = 0;
        }
    }
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }
    
    // setZeroes(matrix);
    setZerosOptimal(matrix);

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}