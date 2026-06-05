#include <bits/stdc++.h>
using namespace std;

bool canMake(vector<int>& logs, int k, int x) {
    long long count = 0;
    for(int v : logs)    count += v / x;
    return count >= k;
}

int maximizeSecureDelivery(vector<int>& deliveryLogs, int k) {
    int low = 1;
    int high = *max_element(deliveryLogs.begin(), deliveryLogs.end());
    int best = 0;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(canMake(deliveryLogs, k, mid)) {
            best = mid;
            low = mid + 1;
        }
        else    high = mid - 1;
    }
    return best * (k/2);
}

int main() {
    int n;
    cin >> n;
    vector<int> deliveryLogs(n);
    for(int i = 0; i < n; i++)
        cin >> deliveryLogs[i];
    int k;
    cin >> k;

    cout << maximizeSecureDelivery(deliveryLogs, k);
    return 0;
}