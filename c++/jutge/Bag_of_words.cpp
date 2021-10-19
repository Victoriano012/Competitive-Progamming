#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    map<string, int> bag;
    string input;
    while(cin >> input){
        if(input == "minimum?"){
            if(bag.size() == 0){
                cout << "indefinite minimum" << endl;
            } else cout << "minimum: " << bag.begin()->first << ", " << bag.begin()->second <<  " time(s)" << endl;
        } else if(input == "maximum?"){
            if(bag.size() == 0){
                cout << "indefinite maximum" << endl;
            } else cout << "maximum: " << bag.rbegin()->first << ", " << bag.rbegin()->second <<  " time(s)" << endl;
        } else if(input == "store"){
            string add;
            cin >> add;
            bag[add]++;
        } else if(input == "delete"){
            string add;
            cin >> add;
            if(bag.count(add)){
                bag[add]--;
                if(bag[add] == 0) bag.erase(add);
            }
        }
    }
    return 1;
}