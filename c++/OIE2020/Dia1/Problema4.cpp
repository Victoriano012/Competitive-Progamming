#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> tazos(n);
        vector<int> amigo(n);
        vector<int> nene(n, 1);
        for(int i = 0; i < n; i++) cin >> tazos[i];
        for(int i = 0; i < n; i++) cin >> amigo[i];
        for(int i = 0; i < n; i++) tazos[i]--;
        for(int i = 0; i < n; i++){
            if(tazos[i] != 0){
                int k = i;
                vector<int> restantes = {tazos[i]};
                int c = 1;
                tazos[i] = 0;
                vector<int> dist(n,0);
                bool b = true;
                int h;
                while(b){
                    for(int j: restantes){
                        if(j!=0){
                            j--;
                            nene[k]++;
                            if(i == 0) c--;
                        }
                    }
                    if(dist[amigo[k]] == 0) dist[amigo[k]] = dist[k]+1;
                    else b = false, h = amigo[k];
                    k = amigo[k];
                    if(tazos[k] != 0){
                        restantes.push_back(tazos[k]);
                        tazos[k] = 0;
                        c++;
                    }
                    if(c == 0) b = false;
                }
            }
        }
        for(int i = 0; i < n; i++) cout << nene[i] << ' ';
        cout << endl;
    }
    return 0;
}
