#include <iostream>
#include <set>

using namespace std;

int main(){
    set<string> has;
    set<pair<int, string>> had;
    int game = 1;
    string s;
    bool space = false;
    while(cin >> s){
        if(s == "END" || s == "QUIT"){
            if(!space) space = true;
            else cout << endl;
            cout << "GAME #" << game << endl;
            game++;
            cout << "HAS:" << endl;
            for(string c: has){
                cout << c << endl;
            }
            cout << endl << "HAD:" << endl;
            for(pair<int, string> c: had){
                cout << c.second << endl;
            }
            has.clear();
            had.clear();
        } else {
            pair<int, string> p = make_pair(s.length(), s);
            auto it1 = has.find(s);
            auto it2 = had.find(p);
            if(it1 == has.end()){
                has.insert(s);
                if(it2 != had.end()) had.erase(it2);
            } else {
                has.erase(it1);
                had.insert(p);
            }
        }
    }
}