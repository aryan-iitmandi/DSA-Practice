#include<bits/stdc++.h>
using namespace std;

int divide(int num, int by){

    int result = 0;
    while(num >= by){
        int temp = by;
        int count = 1;

        while((temp << 1) <= num){
            temp = temp << 1;
            count = count << 1;
        }
        num = num - temp;
        result = result + count;
    }
    return result;
}

int main(){

    cout << divide(9938475, 12843);
    return 0;
}