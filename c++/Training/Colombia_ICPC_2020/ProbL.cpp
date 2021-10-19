#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef priority_queue<vi> svi;

vs mapa;
svi seguent;
vvi seen;
int Ans = -1;
int si, sj;
int n, m;

void dfs(){
    if(seguent.empty()) return;
    vi p = seguent.top();
    seguent.pop();
    if(mapa[p[1]][p[2]] == 'S'){
        seen[p[1]][p[2]] = -p[0];
        Ans = -p[0];
        si = p[1];
        sj = p[2];
        return;
    }

    if(seen[p[1]][p[2]] != -1){
        dfs();
        return;
    }

    seen[p[1]][p[2]] = -p[0];

    int i = p[1]-1, j = p[2];
    while(i != -1 && mapa[i][j] == 'X'){
        i--;
    }
    if(i != -1 && seen[i][j] == -1){
        seguent.push({p[0]-1, i, j});
    }

    i = p[1]+1, j = p[2];
    while(i != n && mapa[i][j] == 'X'){
        i++;
    }
    if(i != n && seen[i][j] == -1){
        seguent.push({p[0]-1, i, j});
    }

    i = p[1], j = p[2]-1;
    while(j != -1 && mapa[i][j] == 'X'){
        j--;
    }
    if(j != -1 && seen[i][j] == -1){
        seguent.push({p[0]-1, i, j});
    }

    i = p[1], j = p[2]+1;
    while(j != m && mapa[i][j] == 'X'){
        j++;
    }
    if(j != m && seen[i][j] == -1){
        seguent.push({p[0]-1, i, j});
    }

    dfs();
}

string bfs(int i1, int j1, int a){
    int i = i1+1, j = j1;
    while(i != n && mapa[i][j] == 'X'){
        i++;
    }
    if(i != n && seen[i][j] == a-1){
        if(a == 1) return "D";
        return "D" + bfs(i, j, a-1);
    }

    i = i1, j = j1-1;
    while(j != -1 && mapa[i][j] == 'X'){
        j--;
    }
    if(j != -1 && seen[i][j] == a-1){
        if(a == 1) return "L";
        return "L" + bfs(i, j, a-1);
    }
    
    i = i1, j = j1+1;
    while(j != m && mapa[i][j] == 'X'){
        j++;
    }
    if(j != m && seen[i][j] == a-1){
        if(a == 1) return "R";
        return "R" + bfs(i, j, a-1);
    }

    i = i1-1, j = j1;
    while(i != -1 && mapa[i][j] == 'X'){
        i--;
    }
    if(i != -1 && seen[i][j] == a-1){
        if(a == 1) return "U";
        return "U" + bfs(i, j, a-1);
    }
}

int main(){
    cin >> n >> m;
    mapa = vs(n);
    seen = vvi(n, vi(m, -1));
    for(int i = 0; i < n; i++){
        cin >> mapa[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mapa[i][j] == 'E'){
                seguent.push({0, i, j});
                dfs();
                break;
            }
        }
    }
    cout << Ans << endl;

    if(Ans != -1) cout << bfs(si, sj, Ans) << endl;
}


