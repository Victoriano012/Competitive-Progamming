#include <iostream>
#include <set>

using namespace std;

int main(){
    set<string> paraules1;
    set<string> paraules2;
    string nova;
    bool b = false;
    while(cin >> nova){
        if(nova == "END") break;
        paraules1.insert(nova);
        paraules2.insert(*paraules1.rbegin());
        paraules1.erase(*paraules1.rbegin());
        b = !b;
        if(b){
            paraules1.insert(*paraules2.begin());
            paraules2.erase(*paraules2.begin());
        }
        cout << *paraules1.rbegin() << endl;
    }
    return 1;
}