#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

using ll = long long;

struct line{
    int num;
    map<int, bool> pos; 
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin >> t;
    for(int c = 1; c <= t; ++c){
        ll n, a, b;
        cin >> n;
        
        map<ll, line> cols;
        map<ll, int> rows;
        map<int, vector<int>> max_col, max_row;

        for(int i = 0; i < n; i++){
            cin >> a >> b;
            cols[a].num++;
            cols[a].pos[b] = true;;
            max_col[cols[a].num].push_back(a);
            rows[b]++;
            max_row[rows[b]].push_back(b);
        }

        pair<int, int> Ans;
        auto itc = max_col.rbegin();
        auto itr = max_row.rbegin();
        Ans.first = itc->first + itr->first;
        Ans.second = 0;
        if(itc->first == 1 && itr->first != 1){
            Ans.second = itr->first;
        } else if(itr->first == 1 && itc->first != 1){
            Ans.second = itc->first;
        } else {
            for(int column: itc->second){
                int k = 0;
                int l = itr->second.size();
                for(int i = 0; i < l; ++i){
                    if(cols[column].pos[i]){
                        ++Ans.second;
                    } else {
                        ++k;
                        if(k == itc->first){
                            Ans.second += l-1-i;
                            break;
                        }
                    }
                }
            }

            if(Ans.second == 0){
                --Ans.first;
                Ans.second = itr->second.size() * itc->second.size();
                int r = itr->first;
                itr++;
                if(itr->first == r-1){
                    for(int column: itc->second){
                        int k = 0;
                        int l = itr->second.size();
                        for(int i = 0; i < l; ++i){
                            if(cols[column].pos[i]){
                                ++Ans.second;
                            } else {
                                ++k;
                                if(k == itc->first){
                                    Ans.second += l-1-i;
                                    break;
                                }
                            }
                        }
                    }
                }
                itr--;
                r = itc->first;
                itc++;
                if(itc->first == r-1){
                    for(int column: itc->second){
                        int k = 0;
                        int l = itr->second.size();
                        for(int i = 0; i < l; ++i){
                            if(cols[column].pos[i]){
                                ++Ans.second;
                            } else {
                                ++k;
                                if(k == itc->first){
                                    Ans.second += l-1-i;
                                    break;
                                }
                            }
                        }
                    }
                }
            } else if(Ans.first == 2) Ans.second /= 2;
        }
        
        cout << "Case " << c << ": " << Ans.first << ' ' << Ans.second << endl;
    }
}