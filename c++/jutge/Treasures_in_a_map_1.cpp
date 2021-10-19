#include <iostream>
#include <vector>

using namespace std;

vector<bool> vist;
vector<vector<int> > veins;

void dfs(int i){
    vist[i] = true;
    for(int j: veins[i]){
        if(!vist[j]) dfs(j);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char> > cuadricula(n, vector<char>(m));
    veins = vector<vector<int> >(n*m);
    vector<int> tresors;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> cuadricula[i][j];
        }
    }

    for(int i = 0; i < n*m; i++){
        if(cuadricula[i/m][i%m] != 'X'){
            if(i%m != 0) if(cuadricula[i/m][i%m - 1] != 'X') veins[i].push_back(i-1);
            if(i%m != m-1) if(cuadricula[i/m][i%m + 1] != 'X') veins[i].push_back(i+1);
            if(i/m != 0) if(cuadricula[i/m - 1][i%m] != 'X') veins[i].push_back(i - m);
            if(i/m != n-1) if(cuadricula[i/m + 1][i%m] != 'X') veins[i].push_back(i + m);
            
            if(cuadricula[i/m][i%m] == 't') tresors.push_back(i);
        }
    }

    vector<vector<int> > neigh = veins;

    int r, c;
    cin >> r >> c;
    r--;
    c--;

    vist = vector<bool>(n*m, false);

    dfs(m*r + c);

    bool puc = false;

    vector<bool> watch = vist;

    for(int t: tresors){
        if(vist[t]){
            puc = true;
        }
    }

    if (puc){
        cout << "yes" << endl;
    } else cout << "no" << endl;

    return 1;
}
