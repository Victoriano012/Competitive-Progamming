#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
    int n, m;
    string s;
while(cin >> n >> m){
    vector<pair<int, int>> limits(n, make_pair(0, m));
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            if(s[j] == 'B') limits[i].first = j+1;
            else if(s[j] == 'R' && limits[i].second == m){
                limits[i].second = j;
            }
        }
        if(i != 0 && limits[i].second > limits[i-1].second){
            limits[i].second = limits[i-1].second;
        }
    }

    vector<ll> prev(m+1, 0), curr(m+1, 0);
    prev[limits[0].second] = 1;
    for(int i = limits[0].second-1; i >= limits[0].first; i--){
        prev[i] = prev[i+1]+1;
    }
    for(int i = limits[0].first-1; i >= 0; i--) prev[i] = prev[i+1];
    for(int j = 1; j < n; j++){
        curr[limits[j].second] = prev[limits[j].second];
        for(int i = limits[j].second-1; i >= limits[j].first; i--){
            curr[i] = curr[i+1]+prev[i];
        }
        for(int i = limits[j].first-1; i >= 0; i--) curr[i] = curr[i+1];
        prev = curr;
        curr = vector<ll>(m+1, 0);
    }
    cout << prev[0] << endl;
}
}