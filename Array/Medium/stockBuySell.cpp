#include<bits/stdc++.h>
using namespace std;

int stockBuySell0(vector<int> &prices){
    int profit = 0, maxProfit = INT_MIN;
    for(int i=0; i<prices.size(); i++){
        for(int j=i+1; j<prices.size(); j++){
            profit = prices[j] - prices[i];
            maxProfit = max(maxProfit, profit);
        }
    }
    return maxProfit;
}

int stockBuySell1(vector<int> &prices){
    int minPrice = prices[0], maxProfit = 0;

    for(int i=1; i<prices.size(); i++){
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }
    return maxProfit;
}

int stockBuySell2(vector<int> &prices){
    int minPrice = prices[0], maxProfit = 0;
    int buyDay = -1, sellDay = -1;

    for(int i=1; i<prices.size(); i++){

        if(prices[i] < minPrice){
            minPrice = prices[i];
            buyDay = i + 1;
        }
        
        if(prices[i] - minPrice > maxProfit){
            maxProfit = prices[i] - minPrice;
            sellDay = i + 1;
        }
    }
    if(maxProfit){
        cout << "Buy Day: " << buyDay << " Sell Day: " << sellDay << endl;
    }
    return maxProfit;
}

int main(){
    vector<int> arr;
    int ip;
    while(cin >> ip)
        arr.emplace_back(ip);

    // cout << stockBuySell0(arr);
    // cout << stockBuySell1(arr);
    cout << stockBuySell2(arr);
    return 0;
}