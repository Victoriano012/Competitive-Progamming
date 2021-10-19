#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef vector<long long > vi;

vi conected;
vi s;
map<long long , vector<pair<long long , long long >>> cables;
map<long long , vector<pair<long long , long long >>> cables2;
long long  n, m;

long long  get(long long  n){
    if(conected[n] == -1) return -1;
    if(n != conected[n]){
        conected[n] = conected[get(conected[n])];
    }
    return conected[n];
}

long long  fmin(){
    auto it = cables.rbegin();
    auto it2 = it->second.begin();
    for(long long  i = 0; i < n-1; i++){
        bool t = true;
        while(t){
            while(it2 != it->second.end()){
                pair<long long , long long > p = *it2;
                long long  a = get(p.first);
                long long  b = get(p.second);
                if(a != b){
                    long long  x = min(a, b);
                    conected[a] = x;
                    conected[b] = x;
                    t = false;
                    if(i == n-2) return it->first;
                    it2++;
                    break;
                }
                it2++;
            }
            if(it2 == it->second.end()){
                it++;
                it2 = it->second.begin();
            }
        }
    }
    return it->first;
}

void fmax(map<long long , vector<pair<long long , long long >>>::iterator it){
    auto it2 = it->second.begin();
    for(long long  i = 0; i < n-1; i++){
        bool t = true;
        while(t){
            while(it2 != it->second.end()){
                pair<long long , long long > p = *it2;
                long long  a = get(p.first);
                long long  b = get(p.second);
                if(a != b){
                    long long  x = min(a, b);
                    conected[a] = x;
                    conected[b] = x;
                    cables2[it->first].push_back(p);
                    t = false;
                    it2++;
                    break;
                }
                it2++;
            }
            if(it2 == it->second.end()){
                it++;
                it2 = it->second.begin();
            }
        }
    }
}

long long Answer(map<long long , vector<pair<long long , long long >>>::reverse_iterator it){
    long long Ans = 0;
    auto it2 = it->second.begin();
    for(long long  i = 0; i < n-1; i++){
        bool t = true;
        while(t){
            while(it2 != it->second.end()){
                pair<long long , long long > p = *it2;
                long long  a = get(p.first);
                long long  b = get(p.second);
                if(a != b){
                    Ans += s[a]*it->first*s[b];
                    long long  x = min(a, b);
                    conected[a] = x;
                    conected[b] = x;
                    s[x] = s[a] + s[b];
                    t = false;
                    it2++;
                    break;
                }
                it2++;
            }
            if(it2 == it->second.end()){
                it++;
                it2 = it->second.begin();
            }
        }
    }
    return Ans;
}

int main(){
    cin >> n >> m;
    for(long long  i = 0; i < m; i++){
        long long  a, b, c;
        cin >> a >> b >> c;
        cables[c].push_back(make_pair(a-1, b-1));
    }

    conected = vi(0);
    for(long long  i = 0; i < n; i++){
        conected.push_back(i);
    }

    auto it = cables.find(fmin());

    conected = vi(0);
    for(long long  i = 0; i < n; i++){
        conected.push_back(i);
    }

    fmax(it);

    conected = vi(0);
    for(long long  i = 0; i < n; i++){
        conected.push_back(i);
    }
    
    s = vi(n, 1);
    
    cout << Answer(cables2.rbegin()) << endl;
    cin >> n;
}