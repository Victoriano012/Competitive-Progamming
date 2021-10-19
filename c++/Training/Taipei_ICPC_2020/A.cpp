#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool func(int n){
    for(int i = 1; i*i <= 2*n; i++){
        if(i*i < (n+1)/2) continue;
        if(n %i == 0) return true;
    }
    return false;
}

int main(){
    int t, n;
    cin >> t;
    for(int x = 0; x < t; x++){
        cin >> n;
        if(func(n)){
            cout << 1 << endl;
        } else cout << 0 << endl;
    }

}