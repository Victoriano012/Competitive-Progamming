#include <iostream>
#include <vector>
#include <set>

using namespace std;

using vi = vector<int>;
using si = set<int>;
using vsi = vector<si>;

vi num;
vsi edges;
int e = -1;

int odd_cicles(int a){
    int Ans = 0;
    for(int i: edges[a]){
        if(num[i] == -1){
            num[i] = num[a]+1;
            Ans += odd_cicles(i);
        } else if((num[i] - num[a])%2 == 0){
            if(Ans == 0){
                Ans = 1;
                e = i;
            }
            else return 2;
        }
    }
    return Ans;
}

void erase(int i){

}

int main(){
    int t; cin >> t;
    while(t--){
        e = -1;
        int n, m; cin >> n >> m;
        edges = vsi(n);
        for(int i = 0; i < m; ++i){
            int a, b; cin >> a >> b;
            --a; --b;
            edges[a].insert(b);
            edges[b].insert(a);
        }
        num = vi(n);
        int k = 0;
        for(int i = 0; i < n; ++i){
            if(num[i] == -1){
                num[i] = 0;
                k += odd_cicles(i);
                if(k > 1) break;
            }
        }
        si Ans;
        if(k > 1) cout << "not smol" << endl;
        else{
            if(k == 1){
                Ans.insert(e);
                erase(e);
            }

        }
        cout << Ans.size() << endl;
        for(auto it = Ans.begin(); it != Ans.end(); );
    }
}