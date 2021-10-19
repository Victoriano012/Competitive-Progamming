#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<string> v;
vector<vector<bool>> seen;
queue<pair<pair<int, int>, int>> nexto;
int n, m;

int dfs(){
	while(!nexto.empty()){
		pair<int, int> pos = nexto.front().first;
		int dist = nexto.front().second;
		nexto.pop();
		if(v[pos.first][pos.second] == 'T') return dist;
		if(pos.first > 0 && v[pos.first-1][pos.second] != '#' && !seen[pos.first-1][pos.second]){
			--pos.first;
			seen[pos.first][pos.second] = true;
			nexto.push(make_pair(pos, dist+1));
			++pos.first;
		}
		if(pos.first < n-1 && v[pos.first+1][pos.second] != '#' && !seen[pos.first+1][pos.second]){
			++pos.first;
			seen[pos.first][pos.second] = true;
			nexto.push(make_pair(pos, dist+1));
			--pos.first;
		}
		if(pos.second > 0 && v[pos.first][pos.second-1] != '#' && !seen[pos.first][pos.second-1]){
			--pos.second;
			seen[pos.first][pos.second] = true;
			nexto.push(make_pair(pos, dist+1));
			++pos.second;
		}
		if(pos.second < m-1 && v[pos.first][pos.second+1] != '#' && !seen[pos.first][pos.second+1]){
			++pos.second;
			seen[pos.first][pos.second] = true;
			nexto.push(make_pair(pos, dist+1));
			--pos.second;
		}
	}
	return -1;
}

int derecha(pair<int, int> pos, int dir, pair<int, int>& beg){
	int Ans = 1;
	while(true){
		if(pos == beg) return -1;
		if(v[pos.first][pos.second] == 'T') return Ans;
		if((dir == 0 && v[pos.first][pos.second+1] != '#') ||
		(dir == 1 && v[pos.first+1][pos.second] != '#') ||
		(dir == 2 && v[pos.first][pos.second-1] != '#') ||
		(dir == 3 && v[pos.first-1][pos.second] != '#')   ) {
			dir += 1;
			dir %= 4;
		}
		if((dir == 0 && v[pos.first-1][pos.second] == '#') ||
		  (dir == 1 && v[pos.first][pos.second+1] == '#') ||
		  (dir == 2 && v[pos.first+1][pos.second] == '#') ||
		  (dir == 3 && v[pos.first][pos.second-1] == '#')   ) {
			dir += 3;
			dir %= 4;
		} else {
			if(dir == 0) --pos.first;
			else if(dir == 1) ++pos.second;
			else if(dir == 2) ++pos.first;
			else if(dir == 3) --pos.second;
			++Ans;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(cin >> m >> n){
		v = vector<string>(n);
		seen = vector<vector<bool>>(n, vector<bool>(m, false));
		for(int i = 0; i < n; ++i) cin >> v[i];
		pair<int, int> begin = make_pair(n-1, 0);
		for(int j = 0; j < m; ++j){
			if(v[n-1][j] == '.'){
				begin.second = j;
				break;
			}
		}
		while(!nexto.empty()) nexto.pop();
		nexto.push(make_pair(begin, 0));
		seen[begin.first][begin.second] = true;
		int best = dfs();
		if(best == -1){
			cout << "IMPOSIBLE" << endl;
		} else {
			int dret = derecha(make_pair(begin.first-1, begin.second), 0, begin);
			if(dret == -1) cout << "INF" << endl;
			else if(dret == best) cout << "IGUAL" << endl;
			else cout << dret - best << endl;
		}
	}
}