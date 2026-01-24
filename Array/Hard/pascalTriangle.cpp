#include <bits/stdc++.h>
using namespace std;

// Time: O(n)
// Space: O(n)
vector<long long> generateNthRow(int n) {
    vector<long long> row;
    long long val = 1;
    row.push_back(val);

    for (int k = 1; k < n; k++) {
        val = val * (n - k) / k;
        row.push_back(val);
    }
    return row;
}

// Time: O(n^2)
// Space: O(n^2)
vector<vector<long long>> pascalTriangle(int n) {
    vector<vector<long long>> triangle;

    for (int i = 0; i < n; i++) {
        vector<long long> row(i + 1, 1);

        for (int j = 1; j < i; j++) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        triangle.push_back(row);
    }
    return triangle;
}

int main() {
    int n;
    cin >> n;

    // Print nth row
    // vector<long long> nthRow = generateNthRow(n);
    // for (auto it : nthRow) {
    //     cout << it << " ";
    // }
    // cout << endl;

    // Print full Pascal Triangle
    vector<vector<long long>> result = pascalTriangle(n);
    for (auto &row : result) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
