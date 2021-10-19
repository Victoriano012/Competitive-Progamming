#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef set<int> si;

int n;
pair<int, int> nexto;
si dists;

void funcion(vi& Ans, vi& curr_dist, set<int>::reverse_iterator it){
    if(nexto.first > nexto.second) return;
    for(; it != dists.rend(); it++){
        if(curr_dist[*it] > 0){
            break;
        }
    }



    Ans[nexto.first] = Ans[n-1] - *it;
    vi errased;
    bool b = true;
    for(int i = 0; i < nexto.first; i++){
        int r = Ans[nexto.first] - Ans[i];
        if(curr_dist[r] == 0){
            b = false;
            break;
        } else {
            errased.push_back(r);
            curr_dist[r]--;
        }
    }
    for(int i = n-1; i > nexto.second; i--){
        int r = Ans[i] - Ans[nexto.first];
        if(curr_dist[r] == 0){
            b = false;
            break;
        } else {
            errased.push_back(r);
            curr_dist[r]--;
        }
    }
    if(b){
        nexto.first++;
        funcion(Ans, curr_dist, it);
        if(nexto.first > nexto.second) return;
        nexto.first--;
    }
    for(int x : errased){
        curr_dist[x]++;
    }



    errased.clear();
    Ans[nexto.second] = *it;
    b = true;
    for(int i = 0; i < nexto.first; i++){
        int r = Ans[nexto.second] - Ans[i];
        if(curr_dist[r] == 0){
            b = false;
            break;
        } else {
            errased.push_back(r);
            curr_dist[r]--;
        }
    }
    for(int i = n-1; i > nexto.second; i--){
        int r = Ans[i] - Ans[nexto.second];
        if(curr_dist[r] == 0){
            b = false;
            break;
        } else {
            errased.push_back(r);
            curr_dist[r]--;
        }
    }
    if(b){
        nexto.second--;
        funcion(Ans, curr_dist, it);
        if(nexto.first > nexto.second) return;
        nexto.second++;
    }
    for(int x : errased){
        curr_dist[x]++;
    }
}

int main(){
    int t, a;
    cin >> t;
    while(t--){
        cin >> n;
        vi dist(1e6+1, 0);
        vi Ans(n, 0);
        dists.clear();
        for(int i = 0; i < n*(n-1)/2; i++){
            cin >> a;
            dist[a]++;
            dists.insert(a);
        }
        Ans[0] = 0;
        dist[Ans[n-1]]--;
        
        nexto = make_pair(1, n-2);

        auto it = dists.rbegin();
        Ans[n-1] = *it;
        funcion(Ans, dist, it);

        bool s = false;
        for(int i: Ans){
            if(s) cout << ' ';
            else s = true;
            cout << i;
        }
        cout << endl;
    }
}

// 2                                                                                                                       1                                                                                                                                                                                                                                               3                                                                                                                       1 2                                                                                                                     1                                                                                                                                                                                                                                               4                                                                                                                       1 2 3                                                                                                                   1 2                                                                                                                     1                                                                                                                                                                                                                                               5                                                                                                                       1 2 3 4                                                                                                                 1 2 3                                                                                                                   1 2                                                                                                                     1                                                                                                                                                                                                                                               6                                                                                                                       1 2 3 4 5                                                                                                               1 2 3 4                                                                                                                 1 2 3                                                                                                                   1 2                                                                                                                     1                                                                                                                                                                                                                                               7                                                                                                                       1 2 3 4 5 6                                                                                                             1 2 3 4 5                                                                                                               1 2 3 4                                                                                                                 1 2 3                                                                                                                   1 2                                                                                                                     1                                                                                                                                                                                                                                               8                                                                                                                       1 2 3 4 5 6 7                                                                                                           1 2 3 4 5 6                                                                                                             1 2 3 4 5                                                                                                               1 2 3 4                                                                                                                 1 2 3                                                                                                                   1 2                                                                                                                     1                                                                                                                                                                                                                                               9                                                                                                                       1 2 3 4 5 6 7 8                                                                                                         1 2 3 4 5 6 7                                                                                                           1 2 3 4 5 6                                                                                                             1 2 3 4 5                                                                                                               1 2 3 4                                                                                                                 1 2 3                                                                                                                   1 2                                                                                                                     1                                                                                                                                                                                                                                               10                                                                                                                      1 2 3 4 5 6 7 8 9                                                                                                       1 2 3 4 5 6 7 8                                                                                                         1 2 3 4 5 6 7                                                                                                           1 2 3 4 5 6                                                                                                             1 2 3 4 5                                                                                                               1 2 3 4                                                                                                                 1 2 3                                                                                                                   1 2                                                                                                                     1                                                                                                                                                                                                                                               11                                                                                                                      1 2 3 4 5 6 7 8 9 10                                                                                                    1 2 3 4 5 6 7 8 9                                                                                                       1 2 3 4 5 6 7 8                                                                                                         1 2 3 4 5 6 7                                                                                                           1 2 3 4 5 6                                                                                                             1 2 3 4 5                                                                                                               1 2 3 4                                                                                                                 1 2 3                                                                                                                   1 2                                                                                                                     1                                                                                                                                                                                                                                               12                                                                                                                      1 2 3 4 5 6 7 8 9 10 11                                                                                                 1 2 3 4 5 6 7 8 9 10                                                                                                    1 2 3 4 5 6 7 8 9                                                                                                       1 2 3 4 5 6 7 8                                                                                                         1 2 3 4 5 6 7                                                                                                           1 2 3 4 5 6                                                                                                             1 2 3 4 5                                                                                                               1 2 3 4                                                                                                                 1 2 3                                                                                                                   1 2                                                                                                                     1                                                                                                                                                                                                                                               13                                                                                                                      1 2 3 4 5 6 7 8 9 10 11 12                                                                                              1 2 3 4 5 6 7 8 9 10 11                                                                                                 1 2 3 4 5 6 7 8 9 10                                                                                                    1 2 3 4 5 6 7 8 9                                                                                                       1 2 3 4 5 6 7 8                                                                                                         1 2 3 4 5 6 7                                                                                                           1 2 3 4 5 6                                                                                                             1 2 3 4 5                                                                                                               1 2 3 4                                                                                                                 1 2 3                                                                                                                   1 2                                                                                                                     1                                                                                                                                                                                                                                               14                                                                                                                      1 2 3 4 5 6 7 8 9 10 11 12 13                                                                                           1 2 3 4 5 6 7 8 9 10 11 12                                                                                              1 2 3 4 5 6 7 8 9 10 11                                                                                                 1 2 3 4 5 6 7 8 9 10                                                                                                    1 2 3 4 5 6 7 8 9                                                                                                       1 2 3 4 5 6 7 8                                                                                                         1 2 3 4 5 6 7                                                                                                           1 2 3 4 5 6                                                                                                             1 2 3 4 5                                                                                                               1 2 3 4                                                                                                                 1 2 3                                                                                                                   1 2                                                                                                                     1                                                                                                                                                                                                                                               15                                                                                                                      1 2 3 4 5 6 7 8 9 10 11 12 13 14                                                                                        1 2 3 4 5 6 7 8 9 10 11 12 13                                                                                           1 2 3 4 5 6 7 8 9 10 11 12                                                                                              1 2 3 4 5 6 7 8 9 10 11                                                                                                 1 2 3 4 5 6 7 8 9 10                                                                                                    1 2 3 4 5 6 7 8 9                                                                                                       1 2 3 4 5 6 7 8                                                                                                         1 2 3 4 5 6 7                                                                                                           1 2 3 4 5 6                                                                                                             1 2 3 4 5                                                                                                               1 2 3 4                                                                                                                 1 2 3                                                                                                                   1 2                                                                                                                     1                                                                                                                                                                                                                                               16                                                                                                                      1 2 3 4 5 6 7 8 9 10 11 12 13 14 15                                                                                     1 2 3 4 5 6 7 8 9 10 11 12 13 14                                                                                        1 2 3 4 5 6 7 8 9 10 11 12 13                                                                                           1 2 3 4 5 6 7 8 9 10 11 12                                                                                              1 2 3 4 5 6 7 8 9 10 11                                                                                                 1 2 3 4 5 6 7 8 9 10                                                                                                    1 2 3 4 5 6 7 8 9                                                                                                       1 2 3 4 5 6 7 8                                                                                                         1 2 3 4 5 6 7                                                                                                           1 2 3 4 5 6                                                                                                             1 2 3 4 5                                                                                                               1 2 3 4                                                                                                                 1 2 3                                                                                                                   1 2                                                                                                                     1                                                                                                                                                                                                                                               17                                                                                                                      1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16                                                                                  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15                                                                                     1 2 3 4 5 6 7 8 9 10 11 12 13 14                                                                                        1 2 3 4 5 6 7 8 9 10 11 12 13                                                                                           1 2 3 4 5 6 7 8 9 10 11 12                                                                                              1 2 3 4 5 6 7 8 9 10 11                                                                                                 1 2 3 4 5 6 7 8 9 10                                                                                                    1 2 3 4 5 6 7 8 9                                                                                                       1 2 3 4 5 6 7 8                                                                                                         1 2 3 4 5 6 7                                                                                                           1 2 3 4 5 6                                                                                                             1 2 3 4 5                                                                                                               1 2 3 4                                                                                                                 1 2 3                                                                                                                   1 2                                                                                                                     1                                                                                                                                                                                                                                               18                                                                                                                      1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17                                                                               1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16                                                                                  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15                                                                                     1 2 3 4 5 6 7 8 9 10 11 12 13 14                                                                                        1 2 3 4 5 6 7 8 9 10 11 12 13                                                                                           1 2 3 4 5 6 7 8 9 10 11 12                                                                                              1 2 3 4 5 6 7 8 9 10 11                                                                                                 1 2 3 4 5 6 7 8 9 10                                                                                                    1 2 3 4 5 6 7 8 9                                                                                                       1 2 3 4 5 6 7 8                                                                                                         1 2 3 4 5 6 7                                                                                                           1 2 3 4 5 6                                                                                                             1 2 3 4 5                                                                                                               1 2 3 4                                                                                                                 1 2 3                                                                                                                   1 2                                                                                                                     1