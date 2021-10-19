#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int s, e;
    int n, r1, r2;
    string t;
    int d = 0;
    while (cin >> s >> e && (s != 0 || e != 0)){
        d++;
        vector <pair <int, int>> c, a, w;
        int q = 0;
        cin >> n;
        if (n > 0){
            for (int x = 0; x < n; x++){
                cin >> r1 >> t >> r2;
                c.push_back(r1);
                a.push_back(r2);
            }
            sort(c.begin(), c.end());
            sort(a.begin(), a.end());
            while(a != w){
                w = a;
                for(int x = 0; x < a.size() - 1; x++){
                    if (c[x + 1] <= a[x]){
                        c.erase(c.begin() + x);
                        a.erase(a.begin() + x + 1);
                    }
                }
            }
            q += (c[0] - s) / 8;
            for(int x = 0; x < a.size() - 1; x++){
                q += (c[x + 1] - a[x]) / 8;
            }
            q += (e - a[a.size() - 1]) / 8;
        } else {
            q += (e - s) / 8;
        }
        cout << "#" << d << ": " << 8*q << endl;
    }
}
