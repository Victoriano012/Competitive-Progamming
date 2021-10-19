#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int> > con;

int Ans(set<int> r, int t, int s){
    if(t == 2) return(s);
    int a = 0;
    while(s != 0){
        set<int> w = r;
        for(int x: con[*w.begin()]){
            set<int>::iterator it = w.find(x);
            if(it != w.end()){
                w.erase(it);
                s--;
            }
        }
        if(t == 1) a += s;
        else a+= Ans(r, t+1, s);
        r.erase(r.begin());
        s--;
    }
    return(a);
}

int main() {
    int t, n;
    cin >> t;
    for(int x = 0; x < t; x++){
        set<int> r;
        r.clear();
        cin >> n;
        con = vector<vector<int> >(n);
        for(int y = 1; y < n; y++){
            int a, b;
            cin >> a >> b;
            if(a < b) con[a].push_back(b);
            else con[b].push_back(a);
        }
        for(int y = 0; y < n; y++)  r.insert(y);
        int buh = Ans(r, 0, r.size());
        cout << buh << endl;
    }
    return 0;
}
