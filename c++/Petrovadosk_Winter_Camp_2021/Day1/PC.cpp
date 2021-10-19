#include <iostream>
#include <vector>

using namespace std;

vector<int> previ;
vector<vector<int>> edges;
vector<bool> in_cicle;

int dfs(int i){
    for(int j: edges[i]){
        if(j != previ[i]){
            if(previ[j] != -1){
                previ[j] = i;
                return j;
            } else {
                previ[j] = i;
                int x = dfs(j);
                if(x != -1) return x;
            }
        }
    }
    return -1;
}

int count(int n){
    int Ans = 0;
    for(int i: edges[n]){
        if(previ[n] != i && !in_cicle[i]){
            previ[i] = n;
            Ans += count(i);
        }
    }
    if(Ans == 0 && edges[n].size() == 1) Ans = 1;
    return Ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    int t;
    cin >> t;
    for(int x = 0; x < t; ++x){
        int n, a, b;
        cin >> n;
        edges = vector<vector<int>>(n);
        for(int i = 0; i < n; ++i){
            cin >> a >> b;
            --a;
            --b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        
        previ = vector<int>(n, -1);
        previ[0] = 0;
        int first = dfs(0);

        in_cicle = vector<bool>(n, false);
        in_cicle[first] = true;
        for(int i = previ[first]; i != first; i = previ[i]) in_cicle[i] = true;

        int Ans = count(first);
        bool t = (Ans == 0);
        int m = 0, curr_m = 0;

        for(int i = previ[first]; i != first; i = previ[i]){
            int c = count(i);
            Ans += c;
            if(c == 0) curr_m++, curr_m %= 3;
            else curr_m = 0;
            m = max(m, curr_m);
            if(previ[i] == first && t && c == 0) m = 2; 
        }
        
        cout << max(Ans+m, 3) << endl;
    }
}
