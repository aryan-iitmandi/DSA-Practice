#include<bits/stdc++.h>
using namespace std;

void pattern01(int n){
    cout << "---Square Pattern---" << endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern02(int n){
    cout << "---Right Angled Triangle Pattern---" << endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern03(int n){
    cout << "---Number Triangle Pattern---" << endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern04(int n){
    cout << "---Number Triangle Pattern---" << endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern05(int n){
    cout << "---Inverted Right Angled Triangle Pattern---" << endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i+1; j++){
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern06(int n){
    cout << "---Inverted Number Triangle Pattern---" << endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i+1; j++){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    pattern01(n);
    pattern02(n);
    pattern03(n);
    pattern04(n);
    pattern05(n);
    pattern06(n);
    return 0;
}