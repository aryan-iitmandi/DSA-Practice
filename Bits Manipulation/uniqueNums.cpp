#include<bits/stdc++.h>
using namespace std;

vector<int> uniqueNums(vector<int> &arr){
    int xorAll = 0;
    for(auto it: arr)   xorAll ^= it;

    int rightMostSetBit = xorAll & ~(xorAll-1);
    int num1 = 0;
    int num2 = 0;

    for(auto it: arr){
        if(it & rightMostSetBit)    num1 ^= it;
        else    num2 ^= it;
    }
    return {num1, num2};
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 3, 2, 1};

    vector<int> result = uniqueNums(arr);
    cout << result[0] << " " << result[1];
    return 0;
}