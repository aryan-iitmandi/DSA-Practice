#include<bits/stdc++.h>
using namespace std;

bool isAllocationPossible(vector<int> &pages, int nofStudents, int maxPages){
    int allocatedStud = 1;
    int allocatedPages = 0;

    for(int i=0; i<pages.size(); i++){

        if(pages[i] > maxPages)     return false;
        if(allocatedPages + pages[i] <= maxPages)       allocatedPages += pages[i];
        else{
            allocatedStud++;
            allocatedPages = pages[i];
        }
        if(allocatedStud > nofStudents) return false;
    }
    return true;
}

int bookAllocation(vector<int> &pages, int nofStudents){
    if(nofStudents > pages.size())      return -1;

    int low = *max_element(pages.begin(), pages.end());    // minimum student must read
    int high = accumulate(pages.begin(), pages.end(), 0);   // maximum allocated pages a student can get
    int ans = -1;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(isAllocationPossible(pages, nofStudents, mid)){
            ans = mid;
            high = mid - 1;
        }
        else    low = mid + 1;
    }
    return ans;
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)    arr.emplace_back(ip);
    int m = arr.back();
    arr.pop_back();

    cout << bookAllocation(arr, m);
    return 0;
}