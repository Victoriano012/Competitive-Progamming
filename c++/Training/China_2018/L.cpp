#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

vector<int> primes;
vector<bool> is_prime;

bool prime(ll& n){
    for(ll i = 2; i*i <= n; ++i){
        if(n%i == 0) return false;
    }
    return true;
}

void siege(int& n){
    is_prime = vector<bool>(n+1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for(int i = 2; i*i <= n; i++){
        if(is_prime[i]){
            primes.push_back(i);
            for(int j = i*i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
    }
}

ll find_prime(ll i){
    i -= 10;
    if(i%2 == 0) --i;
    while(true){
        if(prime(i)) return i;
        i-=2;
    }
}

int strong(ll& n){
    for(int i: primes){
        if(is_prime[n-i]) return i;
    }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int max_n = 1000;
    siege(max_n);
    int t;
    cin >> t;
    for(int c = 1; c <= t; ++c){
        ll n;
        cin >> n;
        cout << "Case " << c << ":";
        if(n < 12){
            cout << " IMPOSSIBLE" << endl;
        } else {
            vector<ll> Ans(6);
            if(n == 12){
                Ans = {2, 2, 2, 2, 2, 2};
            } else {
                Ans[0] = find_prime(n);
                n -= Ans[0];
                if(n % 2 == 1){
                    Ans[1] = 3;
                    n -= 3;
                } else {
                    Ans[1] = 2;
                    n -= 2;
                }
                Ans[2] = 2;
                Ans[3] = 2;
                n -= 4;

                Ans[4] = strong(n);
                Ans[5] = n-Ans[4];
            }

            for(int i = 0; i < 6; ++i){
                cout << ' ' << Ans[i];
            } 
            cout << endl;
        }
    }
}