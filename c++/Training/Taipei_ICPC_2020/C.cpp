#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main(){
    int t, n, k;
    cin >> t;
    for(int x = 0; x < t; x++){
        cin >> n >> k;
        int pos = 0;
        vi old = {k}, curr;
        for(int i = 2; i < n; i++){
            curr = vi(i, 0);
            curr[0] = (old[0]+1)/2;
            for(int j = 1; j < i-1; j++){
                curr[j] = (old[j]+1)/2 + old[j+1]/2;
            }
            curr[i-1] = old[i-2]/2;
            pos = pos + (old[pos]+1)%2;
            old = curr;
        }
        cout << pos + old[pos]%2 << endl;
    }
}
