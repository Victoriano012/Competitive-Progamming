#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        map<string, int> jocs;
        string s;
        for(int i = 0; i < n; i++){
            cin >> s;
            jocs[s]++;
        }
        int total = n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> s;
            if(jocs[s]*2 < total){
                jocs[s]++;
                total++;
            }
        }
        for(pair<string, int> p: jocs){
            cout << p.first << ' ' << p.second << endl;
        }
        cout << "--------------------" << endl;
    }
}