#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;

void backtracking(vs& v, vs Ans, int pos, int r){
    if(pos == r){
        cout << "{";
        if(Ans.size() > 0){
            for(int x = 0; x < Ans.size() - 1; x++) cout << Ans[x] << ",";
            cout << Ans[Ans.size() - 1];
        }
        cout << "}" << endl;
        return;
    }
    backtracking(v, Ans, pos + 1, r);
    Ans.push_back(v[pos]);
    backtracking(v, Ans, pos + 1, r);
}

int main(){
    vs v, Ans;
    int n;
    cin >> n;
    string s;
    for(int x = 0; x < n; x++){
        cin >> s;
        v.push_back(s);
    }
    backtracking(v, Ans, 0, v.size());
}
