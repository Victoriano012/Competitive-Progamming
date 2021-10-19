#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cout << 'A';
    cout << endl;
    for(int i = 1; i < n-1; i++){
        for(int j = 0; j < n; j++) cout << '.';
        cout << endl;
    }
    if(n > 1){
        cout << '.';
        for(int i = 1; i < n-1; i++) cout << 'A';
        cout << '.' << endl;
    }
}