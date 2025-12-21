#include<bits/stdc++.h>
using namespace std;

//Time Complixity: O(min(a, b))
//Space Complixity: O(1)
int euclidean(int a, int b){
    while (a > 0 && b > 0){
        if (a > b)  a = a % b;
        else b = b % a;
    }
    if (a == 0) return b;
    else return a;
}

int euclideanRecursive(int a, int b){
    cout << "a: " << a << "b: " << b << endl;
    if (b == 0) return b;
    return euclideanRecursive(b, a%b);
}

int euclideanIterative(int a, int b){
    while (a != 0){
        cout << "a: " << a << "b: " << b << endl;
        int r = b % a;
        b = a;
        a = r;
    }
    return b;
}

int main(){
    int n1, n2;
    cin >> n1 >> n2;
    // cout << euclidean(n1, n2) << endl;
    cout << euclideanRecursive(n1, n2) << endl;
    // cout << euclideanIterative(n1, n2) << endl;
    // cout << gcd(n1, n2);
    return 0;
}