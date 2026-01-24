#include<bits/stdc++.h>
using namespace std;

vector<int> spiralTraversal(vector<vector<int>> &matrix){
    int m = matrix.size();
    if(m == 0) return {};
    int n = matrix[0].size();

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    vector<int> result;

    while(top <= bottom && left <= right){

        // top row
        for(int i=left; i<=right; i++){
            result.push_back(matrix[top][i]);
        }
        top++;
        
        // right col
        for(int i=top; i<=bottom; i++){
            result.push_back(matrix[i][right]);
        }
        right--;

        // bottom row
        if(top <= bottom){
            for(int i=right; i>=left; i--){
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // left col
        if(left <= right){
            for(int i=bottom; i>=top; i--){
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return result;
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

    vector<int> result = spiralTraversal(matrix);
    for(int it: result){
        cout << it << " ";
    }
    return 0;
}