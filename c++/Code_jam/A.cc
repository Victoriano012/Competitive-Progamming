#include <bits/stdc++.h>

using namespace std;

long long mod = 4.32e13;

long long resta(long long a, long long b){
    return (a-b+mod)%mod;
}
long long times(long long a, long long b){
    return (a*b)%mod;
}

long long find_ans(long long a, long long b, long long c, long long d){
    
}

void show(long long x){
    int nano = (x%(long long)(1e9));
    x /= (long long)(1e9);
    int sec = (x%60);
    x /= (long long)(60);
    int min = (x%60);
    x /= (long long)(60);
    int hour = (x);
    cout << " " << hour << " " << min << " " << sec << " " << nano;
}

int main(){
    int t; cin >> t;
    for(int k = 1; k <= t; ++k){
        long long a, b, c;
        cin >> a >> b >> c;
        long long x = resta(a,b);
        long long y = resta(a,c);
        vector<pair<int, int>> v = {
            {11, 719},
            {11, 108},
            {719, 108},
            {108, 719},
            {719, 11},
            {108, 11},
        }
        for(pair<int, int> p: v){
            if(times(x, p.second) == times(y, p.first)){
                find_ans(p.first, p.second, x, y);
            }
        }
    }
}