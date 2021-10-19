#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using vpivi = vector<pair<int,vector<int>>>;
using vi = vector<int>;
using vb = vector<bool>;
using pii = pair<int, int>;

vpivi veins;
vi dist;
int INF = 10e4+1;

pii dfs(int i){
    int a = 1, b = 1, c = INF;
    bool some = false;
    for(int j: veins[i].second){
        if(dist[j] == -1){
            some = true;
            dist[j] = dist[i] + 1;
            pii hab = dfs(j);
            a += hab.first;
            b = max(b, hab.first);
            c = min(c, hab.second);
        }
    }
    if(!some) return {1, (dist[i]+1)/2};
    if(c <= dist[i]) return {a, c};
    return {b, c};
}

int main(){
    int t;
    cin >> t;
    for(int x = 0; x < t; x++){
        int n;
        cin >> n;
        veins = vpivi(n, {0, vi(0)});
        for(int i = 1; i < n; i++){
            int a, b;
            cin >> a >> b;
            veins[a].second.push_back(b);
            veins[b].second.push_back(a);
            veins[a].first++;
            veins[b].first++;
        }
        int Ans = 0;
        for(int i = 0; i < n; i++){
            if(veins[i].first == 1){
                dist = vi(n, -1);
                dist[i] = 0;
                Ans = max(Ans, n - dfs(i).first);
            }
        }
        cout << Ans << endl;
    }
    return 0;
}
