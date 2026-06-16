#include<bits/stdc++.h>
using namespace std;

string intToBinary(int n){
    string binary = "";
    while(n > 0){
        binary += (n % 2) + '0';
        n /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

int main(){

    int n = 13;
    // cout << intToBinary(12);
    cout << (~n+1) << endl;
    cout << (13 & 7) << endl;
    cout << (13 | 7) << endl;

    // left shift 
    // n << k = n × 2^k
    cout << (1 << 1) << endl;

    // right shift
    // n >> k = n / 2^k
    cout << (20 >> 2) << endl;

    // swap without third variable using xor
    int a = 10, b = 20;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << a << " " << b << endl;

    int num = 13;
    int i = 2;
    // check ith bit
    if((num & (1 << i)))    cout << "bit is set to 1" << endl;

    // set ith bit
    num | (1 << i);

    // clear ith bit
    num & ~(1 << i);

    // toggle ith bit
    num ^ (1 << i);

    // check power of 2
    n && !(n & (n-1));

    // check odd
    n & 1;

    return 0;
}