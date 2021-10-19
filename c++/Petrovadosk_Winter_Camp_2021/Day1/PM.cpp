#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<pair<int, int>> u(n);
		double s = 0;
		for(int i = 0; i < n; ++i){
			int a; cin >> a;
			s += a;
			u[i] = make_pair(a, i+1);
		}
		sort(u.begin(), u.end());
		double p, q; cin >> p >> q;
		int i = n-1, j = 0;
		while(s/(i+1) * p/q < u[i].first){
			s -= u[i].first;
			--i;
		}
		int least = i-j, top = i, bot = j, t = u[i].first;
		double s2 = s, k;
		while(i < n-1){
			s -= u[j].first;
			++j;
			while(i < n-1 && s/(i+1-j) * p/q >= u[i].first){
				++i;
				s += u[i].first;
			}
			if(s/(i+1-j) * p/q < u[i].first){
				s -= u[i].first;
				--i;
			}
			if(i-j > least) least = i-j, top = i, bot = j, s2 = s, k = i+1-j, t = u[i].first;
			else if(i-j == least) top = i;
		}

		s2 -= u[bot].first;
		--bot;
		while(bot >= 0 && (s2+u[bot].first)/k * p/q >= t) --bot;
		++bot;

		cout << n-1-top+bot << endl;
		vector<int> Ans;
		for(int x = 0; x < bot; ++x) Ans.push_back(u[x].second);
		for(int x = top+1; x < n; ++x) Ans.push_back(u[x].second);
		sort(Ans.begin(), Ans.end());
		bool space = false;
		for(int k: Ans){
			if(space) cout << ' ';
			else space = true;
			cout << k;
		}
		cout << endl;
	}
}
