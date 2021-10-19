#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef set<int> si;

vvvi graf;
int n, m, k, a, b, c, d, s, t;
vb seen;

si numeros;

bool dfs(int pos, int k){
    for(vi v: graf[pos]){
        if(k >= v[1] && k <= v[2]){
            if(v[0] == t) return true;
            if(!seen[v[0]]){
                seen[v[0]] = true;
                if(dfs(v[0], k)){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    cin >> n >> m >> k >> s >> t;
    s--;
    t--;
    graf = vvvi(n);
    numeros = si();
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c >> d;
        graf[a-1].push_back({b-1, c, d});
        numeros.insert(c);
        numeros.insert(d+1);
    }

    int Ans = 0;
    auto it = numeros.begin();
    int prev = *it;
    for(it++; it != numeros.end(); it++){
        seen = vb(n, false);
        seen[s] = true;
        if(dfs(s, prev)){
            Ans += *it-prev;
        }
        prev = *it;
    }
    cout << Ans << endl;
    cin >> Ans;
}