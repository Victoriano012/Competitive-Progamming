#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, t;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        vector<int> a(n);
        for(int j = 0; j < n; j++) cin >> a[j];
        int Ans = n;

        vector<int> sum(n+1);
        for(int j = 0; j < n; j++){
            sum[j+1] = sum[j] + a[j];
        }
    }
}