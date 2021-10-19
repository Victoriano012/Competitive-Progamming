#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int t; cin >> t;
    char c;
    while(t--){
        vector<int> v(3);
        cin >> v[0] >> v[1] >> v[2];
        sort(v.begin(), v.end());
        if(v[2] < 58){
            for(int i = 0; i < 100; ++i){
                cin >> c;
                if(c == 'R') cout << "PLACE 1" << endl;
                else if(c == 'G') cout << "PLACE 2" << endl;
                else cout << "DISCARD" << endl;
            }
        } else if(v[0] < 20){
            vector<int> mine = {0, 0, 0};
            int next = 1;
            int r = 0, g = 0, b = 0;
            for(int i = 0; i < 100; ++i){
                cin >> c;
                if(c == 'R'){
                    ++r;
                    if(r == 20){
                        mine[0] = next;
                        ++next;
                    }
                    if(r > 19) cout << "PLACE " << mine[0] << endl;
                    else cout << "DISCARD" << endl;
                } else if(c == 'G') {
                    ++g;
                    if(g == 20){
                        mine[1] = next;
                        ++next;
                    }
                    if(g > 19) cout << "PLACE " << mine[1] << endl;
                    else cout << "DISCARD" << endl;
                } else {
                    ++b;
                    if(b == 20){
                        mine[2] = next;
                        ++next;
                    }
                    if(b > 19) cout << "PLACE " << mine[2] << endl;
                    else cout << "DISCARD" << endl;
                }
            }
        } else {
            int b = 0;
            for(int i = 0; i < 100; ++i){
                cin >> c;
                if(c == 'R'){
                    cout << "PLACE 1" << endl;
                } else if(c == 'G'){
                    if(b < 23) cout << "PLACE 2" << endl;
                    else cout << "DISCARD" << endl;
                } else {
                    ++b;
                    if(b == 23) cout << "EMPTY 2" << endl;
                    if(b > 22) cout << "PLACE 2" << endl;
                    else cout << "DISCARD" << endl;
                }
            }
        }
    }
}
