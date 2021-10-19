#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

typedef long double lb;

vector<lb> p(5);

lb f(lb a){
    lb Ans = 0;
    for(int i = 4; i >= 0; i--){
        Ans *= a;
        Ans += p[i];
    }
    return Ans;
}

int main(){
    cout.setf(ios::fixed);
    cout.precision(5);
    string line;
    lb in;
    int x, t = 1;
    while(getline(cin, line)){
        istringstream iss(line);
        while(iss >> in >> x) p[x] = in;

        cout << "Case " << t << ": zero at ";
        t++;
        lb maxim = f(1);
        if(maxim != 0.0 && f(0.0) != 0.0){
            pair<lb, lb> v = make_pair(0.0, 1.0);
            for(int i = 0; i < 50; i++){
                lb m = (v.first+v.second)/2;
                lb j = f(m);
                if(j == 0) break;
                else if(j*maxim < 0) v.first = m;
                else{
                    v.second = m;
                    maxim = j;
                }
            }

            if((v.first+v.second)/2 - 0.000005 < 0){
                cout << 0.0 << '.' << endl;
            } else{
                cout << (v.first+v.second)/2 - 0.000005 << '.' << endl;
            }
        } else if(maxim == 0.0){
            cout << 1.0 << '.' << endl;
        } else cout << 0.0 << '.' << endl;
        
        for(int i = 0; i < 5; i++) p[i] = 0;
    }
}