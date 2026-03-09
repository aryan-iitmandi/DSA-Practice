#include<bits/stdc++.h>
using namespace std;

int minDaysToMakeBouquets(vector<int> &arr, int nofBouquets, int nofRoses){
    if(nofBouquets * nofRoses > arr.size())    return -1;

    int low = *min_element(arr.begin(), arr.end());
    int high = *max_element(arr.begin(), arr.end());

    while(low < high){
        int mid = low + (high - low)/2;
        int bouquetsMade = 0, rosesMade = 0;

        for(auto day: arr){
            if(day <= mid){
                rosesMade++;
                if(rosesMade == nofRoses){
                    bouquetsMade++;
                    rosesMade = 0;
                }
            }
            else    rosesMade = 0;
        }

        if(bouquetsMade >= nofBouquets)    high = mid;
        else    low = mid + 1;
    }
    return low;
}

int main(){
    vector<int> roses;
    int ip;
    while(cin >> ip)    roses.emplace_back(ip);
    int nofRoses = roses.back();
    roses.pop_back();
    int nofBouquets = roses.back();
    roses.pop_back();

    cout << minDaysToMakeBouquets(roses, nofBouquets, nofRoses) << endl;
    return 0;
}