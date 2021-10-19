#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, w;
    pair<int, int> Ans;
    map<int, int> m;
    while(cin >> n){
        m.clear();
        for(int i = 0; i < n; i++){
            cin >> w;
            m[w]++;
        }
        Ans = make_pair(0,0);
        for(auto it = m.begin(); it != m.end(); it++){
            if(it->second >= Ans.first){
                Ans.first = it->second;
                Ans.second = it->first;
            }
        }
        cout << Ans.first << " " << Ans.second << endl;
    }
}