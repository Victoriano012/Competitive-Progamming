#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using vi = vector<int>;
int d, m;
vi dist, Ans, c;

void find(int t, int prev){
    dist[t]++;
    if(dist[c[t]] == 0){
        dist[c[t]] = dist[t];
        find(c[t], t);
        if(d <= dist[t]) Ans[t] = m;
        else Ans[t] = Ans[c[t]]+1;
    } else {
        if(dist[c[t]] == 1 && c[t] != prev){
            Ans[t] = Ans[c[t]] + 1;
        } else{
            d = dist[c[t]];
            m = dist[t] - dist[c[t]] + 1;
            Ans[t] = m;
        }
    }
}

int main() {
    int n;
    while(cin >> n){
        c = vi(n), dist = vi(n, 0), Ans = vi(n, 0);
        for(int i = 0; i < n; i++) cin >> c[i];
        for(int i = 0; i < n; i++){
            if(Ans[i] == 0){
                d = n+1;
                find(i, -1);
            }
        }
        for(int i: Ans){
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}