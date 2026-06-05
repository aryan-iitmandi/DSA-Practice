#include <bits/stdc++.h>
using namespace std;

int findMinimumGroups(vector<int> security) {
    unordered_map<int,int> freq;
    int minFreq = INT_MAX;
    int ans = INT_MAX;

    for(int x : security)    freq[x]++;
    for(auto &p : freq)     minFreq = min(minFreq, p.second);

    for(int g = minFreq; g >= 1; g--) {
        int groups = 0;
        bool valid = true;

        for(auto &p : freq) {
            int f = p.second;
            int numGroups = f / (g + 1);
            int remainder = f % (g + 1);

            if(remainder == 0)    groups += numGroups;
            else if(remainder + numGroups >= g)     groups += numGroups + 1;
            else {
                valid = false;
                break;
            }
        }
        if(valid)    ans = min(ans, groups);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> security(n);
    for(int i = 0; i < n; i++)      cin >> security[i];

    cout << findMinimumGroups(security);
    return 0;
}