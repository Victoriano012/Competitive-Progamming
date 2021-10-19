#include <bits/stdc++.h>
 
#define F first
#define S second
 
using namespace std;
 
using ll = long long;
 
using P = pair<ll, ll>;
using VB = vector<bool>;
using VI = vector<long long>;
using VS = vector<string>;
using VC = vector<char>;
using VP = vector<P>;
 
using VVI = vector<VI>;
using VVP = vector<VP>;
using VVC = vector<VC>;
using VVB = vector<VB>;
 
using VVVI = vector<VVI>;

const ll LIM = 1000001;
VVI pre(1000002);

void precalcula() {
    for(int i = 1; i < LIM; i++) {
        for(int j = 1; i*j + i < LIM; j++) {
            if(((i*j + i)^(i*j)) == i) {
				pre[i*j + i].push_back(i*j);
			}
        }
    }
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	precalcula();
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		VI v;
        vector<int> M(LIM, 0);
		for(int i = 0; i < n; i++) {
			int a; cin >> a;
            ++M[a];
            if(M[a] == 1) v.push_back(a);
		}

		ll res = 0;
		for(int i = 0; i < n; ++i) {
            int l = pre[v[i]].size();
			for(int j = 0; j < l; j++) {
				res += M[pre[v[i]][j]]*M[v[i]];
			}
		}
		cout << res << endl;
	}
}