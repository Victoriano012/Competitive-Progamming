#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;

void backtracking(vs& v, vs Ans, int pos, int n, int& a, int size){
    if(pos == n){
        cout << "{";
        for(int x = 0; x < size - 1; x++) cout << Ans[x] << ",";
        cout << Ans[size - 1];
        cout << "}" << endl;
        return;
    }
    if(n - pos + size > a){
        backtracking(v, Ans, pos + 1, n, a, size);
    }
    if(size < a){
        Ans.push_back(v[pos]);
        backtracking(v, Ans, pos + 1, n, a, size + 1);
    }
}

int main(){
    vs v, Ans;
    int n, a;
    cin >> a >> n;
    if(a == 0){
        cout << "{}" << endl;
    } else {
        string s;
        for(int x = 0; x < n; x++){
            cin >> s;
            v.push_back(s);
        }
        backtracking(v, Ans, 0, n, a, 0);
    }
}
