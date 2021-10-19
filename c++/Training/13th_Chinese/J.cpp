#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int k = 0; k < t; ++k){
        int n, a;
        cin >> n >> a;
        int Ans = 3*a;
        for(int i = 1; i < n; i++){
            cin >> a;
            Ans = max(Ans, a+1);
        }
        cout << Ans + Ans%2 << endl;
    }
}