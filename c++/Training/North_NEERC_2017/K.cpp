#include <iostream>

using namespace std;

pair<int, int> div(int& n, int w, int h){
    for(int i = 1; i <= (w+1)/2; i++){
        if(n%i == 0 && n/i <= (h+1)/2) return make_pair(n/i, i);
    }
    return make_pair(-1, -1);
}

int main(){
    freopen("kotlin.in", "r", stdin);
    freopen("kotlin.out", "w", stdout);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int h, w, n;
    cin >> h >> w >> n;
    if(n > ((h+1)/2)*(w+1)/2) cout << "Impossible" << endl;
    else{
        pair<int, int> a = div(n, w, h);
        if(a.first == -1) cout << "Impossible" << endl;
        else{
            for(int i = 1; i <= h; i++){
                for(int j = 1; j <= w; j++){
                    if((i%2 == 0 && i/2 < a.first) || (j%2 == 0 && j/2 < a.second)){
                        cout << '#';
                    } else cout << '.';
                }
                cout << endl;
            }
        }
    }
}