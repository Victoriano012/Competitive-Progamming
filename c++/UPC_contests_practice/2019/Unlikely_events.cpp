#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll pow(int a, int b){
    if(a == 0) return 1;
    int k = pow(a/2, b);
    if(a%2 == 0) return k*k;
    return k*k*b;
}

bool minim(vi a, vi b){
    for(int i = 0; i < 3; i++){
        a[i] += b[i+3];
        b[i] += a[i+3];
    }
    for(int j = 0; j < 6; j++){
        int m = min(a[j], b[j]);
        a[j] -= m;
        b[j] -= m;
    }
    ll x = 1;
    ll y = 1;
    x *= pow(a[0], 2);
    x *= pow(a[1], 3);
    x *= pow(a[2], 5);
    y *= pow(b[0], 2);
    y *= pow(b[1], 3);
    y *= pow(b[2], 5);
    if(y >= x) return true;
    return false;
}

int main(){
    ll n;
    while(cin >> n){
        vi u(6, 0), not_u(6, 0);
        for(ll t = 0; t < n; t++){
            ll a, b;
            char c;
            cin >> a >> c >> b;

            vi i(6, 0);
            if(a == 2) i[0]++;
            else if(a == 3) i[1]++;
            else if(a == 4) i[0]+=2;
            else if(a == 5) i[2]++;
            
            if(b == 2) i[3]++;
            else if(b == 3) i[4]++;
            else if(b == 4) i[3]+=2;
            else if(b == 5) i[5]++;
            else i[3]++, i[4]++;
            
            for(int j = 0; j < 6; j++) i[j] += not_u[j];

            for(int j = 0; j < 3; j++){
                int m = min(i[j], i[j+3]);
                i[j] -= m;
                i[j+3] -= m;
            }

            if(!minim(not_u, u)) not_u = u;
            u = i;
        }
        if(!minim(not_u, u)) not_u = u;
        ll Ans1 = 1, Ans2 = 1;
        Ans1 *= pow(not_u[0], 2);
        Ans1 *= pow(not_u[1], 3);
        Ans1 *= pow(not_u[2], 5);
        Ans2 *= pow(not_u[3], 2);
        Ans2 *= pow(not_u[4], 3);
        Ans2 *= pow(not_u[5], 5);
        cout << Ans1 << '/' << Ans2 << endl;
    }
}