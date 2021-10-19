#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, vi> pivi;
typedef vector<pivi> vpivi;
typedef vector<vpivi> vvpivi;

vvpivi ans(51, vpivi(51, pivi(make_pair(-1, vi()))));

ll pawns(int x, int y){
  if(ans[x][y].first == -1){
    if(x == 1){
      ans[x][y].first = y;
      ans[x][y].second = vi(y, 1);
    } else if(y == 1){
      ans[x][y].first = 0;
      ans[x][y].second = vi(1, 0);
    } else {
      ans[x][y].first = 0;
      ans[x][y].second = vi(y, 0);
      if(ans[x-1][y].first == -1) int i = pawns(x-1, y);
      ans[x][y].second[0] = ans[x-1][y].second[1];
      ans[x][y].first += ans[x][y].second[0];
      for(int i = 1; i < y-1; i++){
        ans[x][y].second[i] = ans[x-1][y].second[i+1];
        ans[x][y].second[i] += ans[x-1][y].second[i-1];
        ans[x][y].first += ans[x][y].second[i];
      }
      ans[x][y].second[y-1] = ans[x-1][y].second[y-2];
      ans[x][y].first += ans[x][y].second[y-1];
    }
  }
  return ans[x][y].first;
}

int main(){
  int r, c;
  while(cin >> r >> c){
    cout << pawns(r, c) << endl;
  }
}