#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    string name, fluct;
    map<int, string> names;
    int n, s, m;
    cin >> name >> n >> fluct;
    s = fluct.length();
    vector<vector<char>> out(1, vector<char>(s, ' '));
    do{
        while(out.size() < n) out.push_back(vector<char>(s, ' '));
        names[n-1] = name;
        if(name.length() > m) m = name.length();
        for(int i = 0; i < s; i++){
            if(fluct[i] == 'U'){
                if(out.size() < n) out.push_back(vector<char>(s, ' '));
                if(out[n-1][i] == ' ') out[n-1][i] = '/';
                else if(out[n-1][i] == '\\') out[n-1][i] = 'X';
                n++;
            } else {
                if(out[n-2][i] == ' ') out[n-2][i] = '\\';
                else if(out[n-2][i] == '/') out[n-2][i] = 'X';
                n--;
            }
        }
    } while(cin >> name >> n >> fluct);
    for(int i = out.size()-1; i >= 0; i--){
        map<int, string>::iterator it = names.find(i);
        if(it != names.end()){
            name = names[i];
            int r = name.size();
            for(int t = m; r < t; t--) cout << ' ';
            cout << name;
        }
        else cout << string(m, ' ');
        cout << '|';
        for(int j = 0; j < s; j++) cout << out[i][j];
        cout << '|' << endl;
    }
    cout << string(m-1, ' ') << '0' << string(s+2, '-') << endl;
    return 1;
}