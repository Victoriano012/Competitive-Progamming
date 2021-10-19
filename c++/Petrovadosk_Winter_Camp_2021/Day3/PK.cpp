#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    string s, r;
    for(int i = 0; i < n; ++i){
        char a;
        int x;
        cin >> a;
        if(a == '?') x = 0;
        else {
            cin >> x;
            if(a == 's') x += 7;
            else if(a == 'e') x += 14;
            else if(a == 'w') x += 21;
        }
        s += char(x);
    }
    for(int i = 0; i < m; ++i){
        char a;
        int x;
        cin >> a;
        if(a == '?') x = 0;
        else {
            cin >> x;
            if(a == 's') x += 7;
            else if(a == 'e') x += 14;
            else if(a == 'w') x += 21;
        }
        r += char(x);
    }
    r += '$' + s;

    int Ans = 0;
    vector<int> kmp(n+m+1, 0);
    kmp[0] = 0;
    for(int i = 1; i <= n+m; ++i){
        if(r[i] == '$'){
            kmp[i] = 0;
            continue;
        }
        int t = kmp[i-1];
        while(r[i] != r[t] && r[t] != 0 && r[i] != 0 && t != -1){
            t = kmp[t-1];
        } 
        
        kmp[i] = t+1;
        if(t == m-1) ++Ans;
    }
    cout << Ans << endl;
    cin >> Ans;
}