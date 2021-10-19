#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

int main(){
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    int i = 0, k = 1;
    while(i < n-1 and v[i] <= v[i+1]) ++i;
    if(i == n-1){
        cout << 0 << endl;
        return 0;
    }
    while(i < n-1 and v[i] >= v[i+1]) ++i;
    for(; i < n-1; ++i){
        ++k;
        while(i < n-1 and v[i] <= v[i+1]) ++i;
        while(i < n-1 and v[i] >= v[i+1]) ++i;
    }
    int Ans = 1;
    int k2 = 1;
    while(k2<k){
        ++Ans;
        k2*=2;
    }
    cout << Ans << endl;
}