#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;

void backtracking(int& n, vi& v, int pos, int& o, int uns){
    if(pos == n){
        cout << v[0];
        for(int x = 1; x < n; x++) cout << " " << v[x];
        cout << endl;
        return;
    }
    if((pos - uns ) < (n - o)){
        v[pos] = 0;
        backtracking(n, v, pos + 1, o, uns);
    }
    if(uns < o){
        v[pos] = 1;
        backtracking(n, v, pos + 1, o, uns + 1);
    }
}

int main(){
    int n, o;
    cin >> n >> o;
    vi v (n);
    backtracking(n, v, 0, o, 0);
}
