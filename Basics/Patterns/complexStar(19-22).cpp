#include<bits/stdc++.h>
using namespace std;

void pattern19(int n){
    cout << "---Diamond void pattern---\n";
    for(int i=1; i<=2*n; i++){
        for(int j=1; j<=2*n; j++){    
            // cout << i << j;
            if(i+j<=n+1 || j-i>=n || i-j>=n || i+j>=3*n+1){
                cout << "* ";
            }
            else{
                cout << "  ";
            }
        }
        cout << endl;
    }cout << endl;
}

// void hollowDiamond(int n){
//     cout << "---Diamond void pattern---\n";
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=n-i+1; j++){
//             cout << "* ";
//         }
//         for(int s=1; s<=2*(i-1); s++){
//             cout << "  ";
//         }
//         for(int j=1; j<=n-i+1; j++){
//             cout << "* ";
//         }
//         cout << endl;
//     }
//     for(int i=n; i>=1; i--){
//         for(int j=1; j<=n-i+1; j++){
//             cout << "* ";
//         }
//         for(int s=1; s<=2*(i-1); s++){
//             cout << "  ";
//         }
//         for(int j=1; j<=n-i+1; j++){
//             cout << "* ";
//         }
//         cout << endl;
//     }
// }

void pattern20(int n){
    cout << "---butterfly pattern---\n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << "* ";
        }
        for(int s=1; s<=2*(n-i); s++){
            cout << "  ";
        }
        for(int j=1; j<=i; j++){
            cout << "* ";
        }
        cout << endl;
    }
    for(int i=n-1; i>=1; i--){
        for(int j=1; j<=i; j++){
            cout << "* ";
        }
        for(int s=1; s<=2*(n-i); s++){
            cout << "  ";
        }
        for(int j=1; j<=i; j++){
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}

// void butterflypattern(int n){
//     cout << "---butterfly pattern---\n";
//     for(int i = 1; i <= 2*n-1; i++){
//         int k = (i <= n) ? i : (2*n - i);
//         for(int j = 1; j <= 2*n; j++){
//             // left wing
//             // cout << i << j << " ";
//             if(j <= k || j > 2*n - k){
//                 cout << "* ";
//             }
//             else{
//                 cout << "  ";
//             }
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

void pattern21(int n){
    cout << "---hollow rectangle pattern---\n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==1 || j==1 || i==n || j==n){
                cout << "* ";
            }
            else{
                cout << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void pattern22(int n){
    cout << "---concentric square pattern---\n";
    for(int i=1; i<=2*n-1; i++){
        for(int j=1; j<=2*n-1; j++){
            cout << n - min({i-1, j-1, 2*n - i - 1, 2*n - j - 1}) << " ";
        }
        cout << endl;
    }
}
int main(){
    int n;
    cin >> n;
    pattern19(n);
    // hollowDiamond(n);
    pattern20(n);
    // butterflypattern(n);
    pattern21(n);
    pattern22(n);
    return 0;
}