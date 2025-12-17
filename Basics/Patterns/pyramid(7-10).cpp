#include<bits/stdc++.h>
using namespace std;

void pattern07(int n){
    cout << "---Pyramid Pattern---" << endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout << "  ";
        }
        for(int j=1; j<=2*i-1; j++){
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern08(int n){
    cout << "---Inverted Pyramid Pattern---" << endl;
    for(int i=n; i>=1; i--){
        for(int j=1; j<=n-i; j++){
            cout << "  ";
        }
        for(int j=1; j<=2*i-1; j++){
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}

void pattern09(int n){
    cout << "---Diamond Pattern---" << endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout << "  ";
        }
        for(int j=1; j<=2*i-1; j++){
            cout << "* ";
        }
        cout << endl;
    }
    for(int i=n-1; i>=1; i--){
        for(int j=1; j<=n-i; j++){
            cout << "  ";
        }
        for(int j=1; j<=2*i-1; j++){
            cout << "* ";
        }
        cout << endl;
    }cout << endl;
}

void pattern10(int n){
    cout << "---Arrow Pattern---" << endl;
    for(int i=1; i<=2*n-1; i++){
        for(int j=1; j<=i; j++){
            if(i<=n){
                cout << "* ";
            }else{
                if(j<=2*n-i){
                    cout << "* ";
                }
            }
        }cout << endl;
    }
}

void hollowPyramid(int n){
    cout << "---Hollow Pyramid Pattern---" << endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout << "  ";
        }
        for(int j=1; j<=2*i-1; j++){
            if(j==1 || j==2*i-1 || i==n){
                cout << "* ";
            }else{
                cout << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void hollowDiamond(int n){
    cout << "---Hollow Diamond Pattern---" << endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout << "  ";
        }
        for(int j=1; j<=2*i-1; j++){
            if(j==1 || j==2*i-1){
                cout << "* ";
            }else{
                cout << "  ";
            }
        }
        cout << endl;
    }
    for(int i=n-1; i>=1; i--){
        for(int j=1; j<=n-i; j++){
            cout << "  ";
        }
        for(int j=1; j<=2*i-1; j++){
            if(j==1 || j==2*i-1){
                cout << "* ";
            }else{
                cout << "  ";
            }
        }
        cout << endl;
    }cout << endl;
}
int main(){
    int n;
    cin >> n;
    pattern07(n);
    pattern08(n);
    pattern09(n);
    pattern10(n);
    hollowPyramid(n);
    hollowDiamond(n);
    return 0;
}