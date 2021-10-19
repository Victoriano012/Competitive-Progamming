#include <iostream>
#include <vector>

using namespace std;

double g = 19112300000 * 4.15287;

int main(){
    int h, w, p;
    double s;
    while(cin >> h >> w >> s >> p){
        if(h==0 && w==0 && s==0 && p==0) break;
        vector<string> map(h);
        for(int i = 0; i < h; i++) cin >> map[i];
        vector<double> people(p);
        for(int i = 0; i < p; i++) cin >> people[i];
        double x, y;
        bool d = false;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(map[i][j] == 'R'){
                    x = i;
                    y = j;
                    d = true;
                    break;
                }
            }
            if(d) break;
        }
        int c = 0;
        d = false;
        int Ans = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(map[i][j] == 'P'){
                    if(g / ((x-i)*(x-i)+(y-j)*(y-j)) / (s*s) > people[c]) Ans++;
                    c++;
                    if(c == p) break;
                }
            }
            if(c == p) break;
        }
        cout << Ans << endl;
    }
}