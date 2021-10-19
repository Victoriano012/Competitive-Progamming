#include <iostream>
#include <vector>

using namespace std;

vector<string> v;
vector<vector<int> > vec;
int n, p, t;

void constuct(){    
    if(t == n){
        for(int i = 0; i < p; i++){
            if(vec[i].size() > 0){
                cout << "subset " << i+1 << ": {" << v[vec[i][0]];
                for(int j = 1; j < vec[i].size(); j++){
                    cout << "," << v[vec[i][j]];
                }
                cout << "}" << endl;
            }
            else cout << "subset " << i+1 << ": {}" << endl;
        }
        cout << endl;
        return;
    }

    for(int i = 0; i < p; i++){
        vec[i].push_back(t);
        t++;
        constuct();
        t--;
        vec[i].pop_back();
    }
    
}

int main(){
    string s;
    v = vector<string>(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s, v.push_back(s);
    cin >> p;
    vec = vector<vector<int> >(p);
    t = 0;

    constuct();
    return 1;
}