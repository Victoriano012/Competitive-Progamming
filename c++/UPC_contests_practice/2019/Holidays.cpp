#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

ll mod = 1e9 + 123;

int n;
vvl A;

vvl mult(vvl a, vvl b);
vvl pow(vvl a, int b);
void mes_i(vvl& a);
void menys_i(vvl& a);
vvl s(int h);

vvl mult(vvl a, vvl b){
    vvl Ans;
    for(int i = 0; i < n; i++){
        vl row;
        for(int j = 0; j < n; j++){
            ll x = 0;
            for(int k = 0; k < n; k++){
                x += a[i][k]*b[k][j];
                x %= mod;
            }
            row.push_back(x);
        }
        Ans.push_back(row);
    }
    return Ans;
}

vvl pow(vvl a, int b){
    if(b == 1) return a;
    vvl k = pow(a, b/2);
    if(b%2 == 0) return mult(k, k);
    return mult(k, mult(k, a));
}

void mes_i(vvl& a){
    for(int i = 0; i < n; i++) a[i][i]++, a[i][i] %= mod;
}

void menys_i(vvl& a){
    for(int i = 0; i < n; i++){
        a[i][i]--;
        if(a[i][i] == -1) a[i][i] += mod;
    }
}

vvl s(int h){
    if(h == 1){
        vvl a1 = A;
        mes_i(a1);
        return a1;
    }
    if(h % 2 == 0){
        vvl Ans = mult(A, s(h-1));
        mes_i(Ans);
        return Ans;
    }
    vvl Ans = pow(A, (h+1)/2);
    mes_i(Ans);
    return mult(Ans, s((h-1)/2));
}

int main(){
    int h;
    while(cin >> n >> h){
        A = vvl(n, vl(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> A[i][j];
            }
        }
        vvl Ans = s(h);
        menys_i(Ans);
        ll t = 0;
        for(int i = 0; i < n; i++){
            t += Ans[i][i];
            t %= mod;
        }
        cout << t << endl;
    }
}