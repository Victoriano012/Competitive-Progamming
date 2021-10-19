#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef vector<string> vs;
typedef map<map<string, int>, int> mmsii;

vs b;
map<string, int> mol;
int n, m;

bool det(int i, int j, bool l, bool r, bool u, bool cr, bool cl){
    if(!u && i != 0 && b[i-1][j] == '|') return false;
    if(!cr && cl && b[i][j] >= 'A' && b[i][j] <= 'Z'){
        mol[b[i].substr(j, 1)]++;
    }
    if(cr && b[i][j] >= 'A'  && b[i][j] <= 'Z'){
        if(j != m-1 && b[i][j+1]>= 'a'  && b[i][j+1] <= 'z'){
            mol[b[i].substr(j, 2)]++;
            if(!det(i, j+1, false, true, u, false, false)) return false;
            r = false;
        } else mol[b[i].substr(j, 1)]++;
    }
    if(cl && b[i][j] >= 'a'  && b[i][j] <= 'z'){
        mol[b[i].substr(j-1, 2)]++;
        if(!det(i, j-1, true, false, u, false, false)) return false;
        l = false;
    }
    if(r && j != m-1){
        if(b[i][j+1] == '-') if(!det(i, j+2, false, true, false, true, false)) return false;
    }
    if(l && j != 0){
        if(b[i][j-1] == '-') if(!det(i, j-2, true, false, false, false, true)) return false;
    }
    if(i != n-1){
        if(b[i+1][j] == '|') if(!det(i+2, j, true, true, true, true, true)) return false;
    }
    return true;
}

bool check(int& i, int& j){
    if(b[i][j] > 'Z') return false;
    if(b[i][j] < 'A') return false;
    if(i != 0 && b[i-1][j] == '|') return false;
    if(j != 0 && b[i][j-1] == '-') return false;
    return true;
}

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    while(cin >> n >> m){
        b = vs(n);
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        mmsii before;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(check(i, j)){
                    mol.clear();
                    if(det(i, j, false, true, false, true, false)) before[mol]++;
                }
            }
        }

        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        mmsii after;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(check(i, j)){
                    mol.clear();
                    if(det(i, j, false, true, false, true, false)) after[mol]++;
                }
            }
        }

        vector<pair<map<string, int>, int>> Ans_b;
        vector<pair<map<string, int>, int>> Ans_a;
        auto pb = before.begin();
        auto pa = after.begin();
        while(pb != before.end() && pa != after.end()){
            if(pa->first < pb->first){
                Ans_a.push_back(*pa);
                pa++;
            } else if(pa->first > pb->first){
                Ans_b.push_back(*pb);
                pb++;
            } else {
                if(pa->second > pb->second){
                    Ans_a.push_back(make_pair(pa->first, pa->second - pb->second));
                } else if(pa->second < pb->second){
                    Ans_b.push_back(make_pair(pb->first, pb->second - pa->second));
                }
                pa++;
                pb++;
            }
        }
        while(pb != before.end()){
            Ans_b.push_back(*pb);
            pb++;
        }
        while(pa != after.end()){
            Ans_a.push_back(*pa);
            pa++;
        }


        int g = 0;
        for(auto p: Ans_b){
            if(g == 1) break;
            g = gcd(p.second, 0);
        }
        for(auto p: Ans_a){
            if(g == 1) break;
            g = gcd(g, p.second);
        }

        for(auto p = Ans_b.begin(); p != Ans_b.end(); p++) p->second /= g;
        for(auto p = Ans_a.begin(); p != Ans_a.end(); p++) p->second /= g;
        
        bool s = false;
        for(auto p: Ans_b){
            if(s) cout << '+';
            else s = true;
            if(p.second != 1) cout << p.second;
            for(auto k: p.first){
                cout << k.first;
                if(k.second != 1) cout << k.second;
            }
        }
        cout << "->";
        s = false;
        for(auto p: Ans_a){
            if(s) cout << '+';
            else s = true;
            if(p.second != 1) cout << p.second;
            for(auto k: p.first){
                cout << k.first;
                if(k.second != 1) cout << k.second;
            }
        }
        cout << endl;
    }
}