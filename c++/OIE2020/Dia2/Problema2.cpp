#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

using pii = pair<int, int>;
using vvpii = vector<vector<pii>>; 
using vspii = vector<set<pii>>; 

vvpii carretera; //cada parella es {a quin va, quanta distancia}
vspii dist; //cada parella es {possible distancia, acumulat}

void dfs(int v, pair<int, int> c){
    for(pii p: carretera[v]){
        pair<int, int> nueva = {c.first + c.second + p.second, c.second + p.second};
        if(dist[p.first].find(nueva) == dist[p.first].end()){
            dist[p.first].insert(nueva);
            auto it = dist[p.first].find(nueva);
            if(it != dist[p.first].begin()){
                it--;
                pii w = *it;
                it++;
                if(w.second < nueva.second){
                    dist[p.first].erase(it);
                } else {  //aquest else esta repetit per l'if gran també
                    if(it != dist[p.first].end()){
                        auto z = ++it;
                        it--;
                        pii l = *z;
                        while(l.second > nueva.second){
                            dist[p.first].erase(z);
                            it = dist[p.first].find(nueva);
                            z = ++it;
                            it--;
                            l = *z;
                        }
                    }
                    dfs(p.first, nueva);
                } 
            } else {  //aquí
                if(it != dist[p.first].end()){
                    auto z = ++it;
                    it--;
                    pii l = *z;
                    while(z != dist[p.first].end() && l.second > nueva.second){
                        dist[p.first].erase(z);
                        it = dist[p.first].find(nueva);
                        z = ++it;
                        it--;
                        if(z != dist[p.first].end()) l = *z;
                    }
                }
                dfs(p.first, nueva);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, m, a, b, c;
        cin >> n >> m;
        carretera = vvpii(n);
        for(int i = 0; i < m; i++){
            cin >> a >> b >> c;
            carretera[a].push_back({b,c});
        }
        dist = vspii(n);
        dist[0].insert({0,0});
        dfs(0, {0,0});
        for(set<pair<int, int>> d: dist){
            if(d == dist[0]) continue;
            if(d.empty()){
                cout << -1 << ' ';
                continue;
            }
            const pair<int, int>& i = (*d.begin());
            cout << i.first << ' ';
        }
        cout << endl;
    }
    return 0;
}
