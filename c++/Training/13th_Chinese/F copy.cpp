#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
using ll = long long;
 
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using vb = vector<bool>;
 
vvi edges;
vvi r_edges;
vs lose;
queue<int> nexto;
vb in_next;
string torns;
 
void act(){
    int p = nexto.front();
    nexto.pop();
    in_next[p] = false;
    bool a = false;
    for(int i = 0; i < 6; i++){
        if(lose[p][i] == 'D'){
            char best = lose[edges[p][0]][(i+1)%6];
            if(best == 'D' || best == torns[i]){
                for(int j: edges[p]){
                    if(lose[j][(i+1)%6] == 'D') best = 'D';
                    else if(lose[j][(i+1)%6] != torns[i]){
                        best = lose[j][(i+1)%6];
                        break;
                    }
                }
            }
            lose[p][i] = best;
            if(best != 'D') a = true;
        }
    }
    if(a){
        for(int j: r_edges[p]){
            if(!in_next[j]){
                nexto.push(j);
                in_next[j] = true;
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
        for(int i = 0; i < m; ++i){
            cin >> a >> b;
            --a, --b;
            edges[a].push_back(b);
            r_edges[b].push_back(a);
        }
        in_next = vb(n, false);
        cin >> torns;
        lose = vs(n, "DDDDDD");
        for(int i = 0; i < n; i++){
            if(edges[i].empty()){
                lose[i] = torns;
                for(int j: r_edges[i]){
                    if(!in_next[j]){
                        nexto.push(j);
                        in_next[j] = true;
                    }
                }
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