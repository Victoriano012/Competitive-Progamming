#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    char c;
    bool t = true, l = true;
    cin >> n >> k;
    vector<bool> old_dir(n), new_dir(n);
    vector<pair<int, vector<int>>> Ans(k, make_pair(0, vector<int>()));
    for(int i = 0; i < n; i++){
        cin >> c;
        c == 'R' ? old_dir[i] = true : old_dir[i] = false;
    }
    new_dir = old_dir;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n-1; j++){
            if(old_dir[j] && !old_dir[j+1]){
                new_dir[j] = false;
                new_dir[j+1] = true;
                Ans[i].second.push_back(j+1);
                Ans[i].first++;
            }
        }
        old_dir = new_dir;
    }
    for(int i = 0; i < k; i++){
        if(new_dir[i]){
            if(l) l = false;
        } else if(!l){
            t = false;
            break;
        }
    }
    for(int i = 0; i < k; i++) if(Ans[i].first == 0){
        t = false;
        break;
    }
    if(!t) cout << -1;
    else{
        for(int i = 0; i < k; i++){
            cout << Ans[i].first;
            for(int j = 0; j < Ans[i].second.size(); j++){
                cout << ' ' << Ans[i].second[j];
            }
            cout << endl;
        }
    }
    return 1;
    return 0;
}