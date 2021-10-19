#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool> > vist;
vector<vector<int> > veins;
int n, m;

void kinda_dfs(int i, int j){
    if(i < j){
        for(int k = 0; k < n; k++) if(vist[j][k]) vist[i][k] = true;
    }
    else{
        for(int k: veins[j]){
            vist[i][k] = true;
            kinda_dfs(i, k);
        }
    }
}

int main(){
    while(cin >> n >> m){
        veins = vector<vector<int> >(n);
        vist = vector<vector<bool> >(n, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            int r, k;
            cin >> r >> k;
            veins[r].push_back(k);
        }

        for(int i = 0; i < n; i++) vist[i][i] = true;

        for(int i = 0; i < n; i++) kinda_dfs(i, i);
        
        for(int i = 0; i < n; i++){
            if(vist[i][0]){
                cout << "1";
            } else cout << "0";
            for(int j = 1; j < n; j++){
                if(vist[i][j]){
                    cout << " 1";
                } else cout << " 0";
            }
            cout << endl;
        }
        cout << "--------------------" << endl;
    }

    return 1;
}