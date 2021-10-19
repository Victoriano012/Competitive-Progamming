#include <iostream>
#include <vector>

using namespace std;


long long primer_prot(vector<bool>& prot, long long& n){
    for(long long i = 0; i < n; i++) if(prot[i]) return i;
    return -1;
}

int main(){
    long long n, m, a, b;
    cin >> n >> m;

    
    vector<long long> padre(m);
    vector<bool> prot(n+m, false);
    long long Ans = 0;
    for(long long i = 0; i < n+m; i++){
        cin >> a >> b;
        if(b >= n){
            padre[b-n] = a;
        }
    }
    for(long long i = m-1; i >= 0; i--){
        if(!prot[i+n] && !prot[padre[i]]){
            prot[padre[i]] = true;
            Ans++;
        }
    }
    long long k = primer_prot(prot, n);
    if(k == -1){
        Ans += (n+1)/2;
    } else {
        for(long long i = k+1; i < n-1; i++){
            if(!prot[i-1] && !prot[i] && !prot[i+1]){
                prot[i] = true;
                Ans++;
                i++;
            }
        }
        if(!prot[n-2] && !prot[n-1] && !prot[0]){
            prot[n-1] = true;
            Ans++;
        }
        if(!prot[n-1] && !prot[0] && !prot[1]){
            prot[0] = true;
            Ans++;
        }
        for(long long i = 1; i < k; i++){
            if(!prot[i-1] && !prot[i] && !prot[i+1]){
                prot[i] = true;
                Ans++;
                i++;
            }
        }

        for(long long i = 0; i < n-1; i++){
            if(!prot[i] && !prot[i+1]){
                prot[i] = true;
                Ans++;
                i++;
            }
        }
        if(!prot[n-1] && !prot[0]){
            prot[n-1] = true;
            Ans++;
        }
    }
    
    cout << Ans << endl;
    
}