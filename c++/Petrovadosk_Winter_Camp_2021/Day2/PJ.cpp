#include <iostream>

using namespace std;

int num(int n){
    int Ans = 0;
    for(int i = 2; i*i <= n; ++i){
        if(n%i == 0){
            ++Ans;
            while(n%i == 0) n /= i;
        }
    }
    if(n > 1) ++Ans;
    return Ans;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << num(n)+num(n+1) << endl;
    }
}
