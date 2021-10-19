#include <iostream>
#include <map>

using namespace std;

int main(){
    int n, t;
    cin >> t;
    for(int i = 0; i < t; i++){
        map<int, int> mapa;
        cin >> n;
        for(int j = 0; j < n; j++){
            string a;
            int b;
            cin >> a >> b;
            mapa[b]++;
        }
        map<int, int> mapa2;
        for(auto it = mapa.rbegin(); it != mapa.rend(); it++){
            mapa2[it->second] = it->first;
        }
        cout << mapa2.rbegin()->second << endl;
    }
}