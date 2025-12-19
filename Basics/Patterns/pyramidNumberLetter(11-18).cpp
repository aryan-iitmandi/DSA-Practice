#include<bits/stdc++.h>
using namespace std;    

void pattern11(int n){
    cout << "---Alternating 0-1 Pyramid Pattern---" << endl;
    int start;
    for(int i=1; i<=n; i++){
        if(i%2==0)  start = 0;
        else start = 1;
        for(int j=1; j<=i; j++){
            cout << start << " ";
            if(start == 0) start = 1;
            else start = 0;
        }
            cout << endl;
    }cout << endl;
}

void pattern12(int n){
    cout << "---Number Crown Pattern---" << endl;
    int spaces = 2*n-2;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << j << " ";
        }
        for(int s=1; s<=spaces; s++){
            cout << "  ";
        }
        spaces -= 2;
        for(int k=i; k>=1; k--){
            cout << k << " ";
        }cout << endl;
    }cout << endl;
}

void pattern13(int n){
    cout << "---Increasing Number Pattern---" << endl;
    int counter = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << counter << " ";
            counter++;
        }cout << endl;
    }cout << endl;
}

void pattern14(int n){
    cout << "---Increasing Letter Pattern---" << endl;
    for(int i=1; i<=n; i++){
        char ch = 'A';
        for(int j=1; j<=i; j++){
            cout << ch << " ";
            ch++;
            if(ch>'Z') ch = 'A';
        }cout << endl;
    }cout << endl;
}

void pattern15(int n){
    cout << "---Decreasing Letter Pattern---" << endl;
    for(int i=n; i>=1; i--){
        char ch = 'A';
        for(int j=1; j<=i; j++){
            cout << ch << " ";
            ch++;
            if(ch>'Z') ch = 'A';
        }cout << endl;
    }cout << endl;
}

void pattern16(int n){
    cout << "---Alpha Ramp Pattern---" << endl;
    char ch = 'A';
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << ch << " ";
        }cout << endl;
        ch++;
        if(ch>'Z') ch = 'A';
    }cout << endl;
}

void pattern17(int n){
    cout << "---Alpha hill Pattern---" << endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout << "  ";
        }
        for(int j=1; j<=2*i-1; j++){
            char ch = 'A';
            if(j<=i){
                cout << char(ch + j - 1) << " ";
            }
            else{
                cout << char(ch + 2*i - j - 1) << " ";
            }
            if(ch >'Z') ch = 'A';
        }
        cout << endl;
    }
    cout << endl;
}

// void alphaHill(int n){
//     cout << "---Alpha Hill Pattern---" << endl;

//     for(int i = 1; i <= n; i++){

//         // 1. Spaces
//         for(int s = 1; s <= n - i; s++){
//             cout << "  ";
//         }

//         // 2. Increasing letters
//         char ch = 'A';
//         for(int j=1; j<=i; j++){
//             cout << ch << " ";
//             ch++;
//         }

//         // 3. Decreasing letters
//         ch -= 2;
//         for(int j=1; j<=i-1; j++){
//             cout << ch << " ";
//             ch--;
//         }

//         cout << endl;
//     }
// }

void pattern18(int n){
    cout << "---Alpha Triangle Pattern---" << endl;
    for(int i=1; i<=n; i++){
        char startchar = 'A' - i + n;
        for(int j=1; j<=i; j++){
            cout << startchar++ << " ";
            if(startchar>'Z') startchar = 'A';
        }cout << endl;
    }cout << endl;
}

int main(){
    int n;
    cin >> n;
    pattern11(n);
    pattern12(n);
    pattern13(n);
    pattern14(n);
    pattern15(n);
    pattern16(n);
    pattern17(n);
    // alphaHill(n);
    pattern18(n);
    return 0;
}