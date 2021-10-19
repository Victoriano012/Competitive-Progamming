#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using ll = long long;

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vs = vector<string>;
using vb = vector<bool>;

vvi edges;
vvi r_edges;
vs lose;
queue<pair<int, int>> nexto;
string torns;
vvi f;
vi conec;

void act(){
    int p = nexto.front().first, i = nexto.front().second;
    nexto.pop();
    
    for(int j: r_edges[p]){
        if(lose[j][(i+5)%6] == 'D'){
            if(torns[(i+5)%6] != lose[p][i]){
                nexto.push(make_pair(j, (i+5)%6));
                lose[j][(i+5)%6] = lose[p][i];
            } else {
                ++f[j][(i+5)%6];
                if(f[j][(i+5)%6] == conec[j]){
                    nexto.push(make_pair(j, (i+5)%6));
                    lose[j][(i+5)%6] = lose[p][i];
                }
            }
        }
    }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    int t;
    cin >> t;
    for(int x = 0; x < t; ++x){
        int n, m, a, b;
        cin >> n >> m;
        edges = vvi(n);
        r_edges = vvi(n);
        conec = vi(n, 0);
        for(int i = 0; i < m; ++i){
            cin >> a >> b;
            --a, --b;
            edges[a].push_back(b);
            ++conec[a];
            r_edges[b].push_back(a);
        }

        vi ends;
        cin >> torns;
        lose = vs(n, "DDDDDD");
        for(int i = 0; i < n; i++){
            if(conec[i] == 0){
                ends.push_back(i);
                lose[i] = torns;
            }
        }

        string actors;
        cin >> actors;
        for(int i = 0; i < 6; i++){
            if(actors[i] == '1'){
                if(torns[i] == 'A') torns[i] = 'B';
                else torns[i] = 'A';
            }
        }
        
        f = vvi(n, vi(6, 0));
        for(int i: ends){
            for(int j: r_edges[i]){
                for(int k = 0; k < 6; k++){
                    if(lose[j][(k+5)%6] == 'D'){
                        if(torns[(k+5)%6] != lose[i][k]){
                            nexto.push(make_pair(j, (k+5)%6));
                            lose[j][(k+5)%6] = lose[i][k];
                        } else {
                            ++f[j][(k+5)%6];
                            if(f[j][(k+5)%6] == conec[j]){
                                nexto.push(make_pair(j, (k+5)%6));
                                lose[j][(k+5)%6] = lose[i][k];
                            }
                        }
                    }
                }
            }
        }


        while(!nexto.empty()){
            act();
        }

        for(int i = 0; i < n; i++){
            if(lose[i][0] == 'D') cout << 'D';
            else if(lose[i][0] == 'A') cout << 'B';
            else cout << 'A';
        }
        cout << endl;
    }
}