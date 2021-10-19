#include <iostream>
#include <map>

using namespace std;

int main(){
    map<string, int> casino;
    string nom, accio;
    while(cin >> nom >> accio){
        if(accio == "wins"){
            int g;
            cin >> g;
            if(casino.count(nom)){
            casino[nom] += g;
            } else cout << nom << " is not in the casino" << endl;
        } else if(accio == "leaves"){
            if(casino.count(nom)){
                cout << nom << " has won " << casino[nom] << endl;
                casino.erase(nom);
            } else cout << nom << " is not in the casino" << endl;
        } else if(accio == "enters"){
            if(casino.count(nom)) cout << nom << " is already in the casino" << endl;
            else{
                casino[nom] = 0;
            }
        }
    }
    cout << "----------" << endl;
    for(map<string, int>::iterator it = casino.begin(); it != casino.end(); ++it){
        cout << it->first << " is winning " << it -> second << endl;
    }
    return 1;
}