#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
vector<int> ref;
 
int get_ref(int n){
    if(n == ref[n]) return n;
    ref[n] = get_ref(ref[n]);
    return ref[n];
}
 
int main(){
    freopen("hidden.in", "r", stdin);
    freopen("hidden.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
    int n;
    cin >> n;
    vector<int> pap(n+1, 0);
    vector<int> n_sons(n+1, 0);
    vector<int> not_taken(n+1, 1);
    vector<set<int>> looks(n+1);
    for(int i = 1; i <= n; i++) looks[i].insert(i);
    ref = vector<int>(n+1);
    for(int i = 1; i <= n; i++) ref[i] = i;
    for(int i = 2; i <= n; i++){
        cin >> pap[i];
        ++n_sons[pap[i]];
        if(pap[i] != 0){
            ref[i] = get_ref(pap[i]);
            not_taken[ref[i]] += not_taken[i];
            looks[ref[i]].insert(looks[i].begin(), looks[i].end());
        }
    }
 
    vector<bool> taken(n+1, false);
    taken[0] = true;
    bool t = true;
    int Ans = 0;
    while(t){
        t = false;
        for(int i = 2; i <= n; i++){
            if(n_sons[i] == 0 && !taken[i] && !taken[pap[i]]){
                t = true;
                taken[i] = true;
                taken[pap[i]] = true;
                looks[ref[i]].erase(i);
                looks[ref[i]].erase(pap[i]);
                ++Ans;
                n_sons[pap[pap[i]]]--;
                not_taken[get_ref(i)] -= 2;
            }
        }
    }
    
    for(int i = 2; i <= n; i++){
        if(pap[i] == 0 && not_taken[i] != 1){
            if(taken[i]){
                pap[i] = 1;
                looks[1].insert(looks[i].begin(), looks[i].end());
            }
            else{
                bool t = true;
                for(int j: looks[1]){
                    if(!taken[j] && i != j){
                        pap[i] = j;
                        taken[i] = true;
                        taken[j] = true;
                        looks[i].erase(i);
                        looks[1].insert(looks[i].begin(), looks[i].end());
                        looks[1].erase(j);
                        t = false;
                        ++Ans;
                        break;
                    }
                }
                if(t){
                    pap[i] = 1;
                    looks[1].insert(looks[i].begin(), looks[i].end());
                }
                ref[i] = 1;
            }
        }
    }
    for(int i = 2; i <= n; i++){
        if(pap[i] == 0){
            if(taken[i]){
                pap[i] = 1;
                looks[1].insert(looks[i].begin(), looks[i].end());
            }
            else{
                bool t = true;
                for(int j: looks[1]){
                    if(!taken[j] && i != j){
                        pap[i] = j;
                        taken[i] = true;
                        taken[j] = true;
                        looks[i].erase(i);
                        looks[1].insert(looks[i].begin(), looks[i].end());
                        looks[1].erase(j);
                        t = false;
                        ++Ans;
                        break;
                    }
                }
                if(t){
                    pap[i] = 1;
                    looks[1].insert(looks[i].begin(), looks[i].end());
                }
                ref[i] = 1;
            }
        }
    }
 
    cout << Ans << endl;
    cout << pap[2];
    for(int i = 3; i <= n; ++i){
        cout << ' ' << pap[i];
    }
    cout << endl;
}