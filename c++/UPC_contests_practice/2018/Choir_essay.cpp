#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<long double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<bool> vb;

int main(){
    cout.setf(ios::fixed);
    cout.precision(3);
    int n, m;
    long double t;
    while(cin >> n >> m >> t){
        long double Ans = -1;
        vvvd graf(n, vvd(0));
        priority_queue<pair<long double, int>> seguent;
        vb seen(n, false);
        for(int i = 0; i < m; i++){
            int a, b;
            vd c(3);
            cin >> a >> b >> c[1] >> c[2];
            c[0] = b;
            graf[a].push_back(c);
            c[0] = a;
            graf[b].push_back(c);
        }
        seguent.push(make_pair(t, n-1));

        while(true){
            if(seguent.empty()) break;
            pair<long double, int> p = seguent.top();
            seguent.pop();
            if(p.first < 0) break;
            if(p.second == 0){
                Ans = p.first;
                break;
            }
            if(seen[p.second]){
                continue;
            }
            seen[p.second] = true;
            for(vd v: graf[p.second]){
                if(!seen[v[0]] && p.first > v[2]){
                    seguent.push(make_pair((p.first - v[2]) / (v[1] + 1) , v[0]));
                }
            }
        }

        if(Ans != -1) cout << Ans << endl;
        else cout << "impossible" << endl;
    }
}
