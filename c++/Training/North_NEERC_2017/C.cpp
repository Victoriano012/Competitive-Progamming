#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<char> v = {'a', 'e', 'i', 'o', 'u', 'y', 'w'};

bool vowel(char c){
    for(char x: v) if(c == x) return true;
    return false;
}


vector<ll> next_ref('z'-'a'+1);

ll find_ref(ll n){
    if(n == next_ref[n]) return n;
    next_ref[n] = find_ref(next_ref[n]);
    return next_ref[n];
}


int main(){
    // freopen("consonant.in", "r", stdin);
    // freopen("consonant.out", "w", stdout);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    string s;
    cin >> s;
    ll l = s.length();

    vector<vector<ll>> con('z'-'a'+1, vector<ll>('z'-'a'+1, 0));
    for(ll i = 0; i < l-1; i++){
        if(!vowel(s[i]) && !vowel(s[i+1])){
            ++con[min(s[i], s[i+1])-'a'][max(s[i], s[i+1])-'a'];
        }
    }


    for(ll i = 0; i <= 'z'-'a'; i++) next_ref[i] = i;
    for(char x: v) next_ref[x -'a'] = 1;

    auto ref = next_ref;
    while(true){
        vector<ll> minim = {10000000, 0, 0};
        bool t = false;
        for(ll i = 0; i < 'z'-'a'; i++){
            if(find_ref(i)!= i) continue;
            for(ll j = i+1; j <= 'z'-'a'; j++){
                if(find_ref(j)!= j) continue;
                if(i == 3 || j == 3){
                    int a = 0;
                }
                if(con[i][j] < minim[0]){
                    minim[0] = con[i][j];
                    minim[1] = i;
                    minim[2] = j;
                    if(minim[0] == 0){
                        t = true;
                        break;
                    }
                }
            }
            if(t) break;
        }

        for(ll i = 0; i <= 'z'-'a'; i++){
            con[min(minim[1], i)][max(minim[1], i)] += con[min(minim[2], i)][max(minim[2], i)];
            next_ref[minim[2]] = minim[1];
        }

        t = true;
        for(ll i = 0; i <= 'z'-'a'; i++){
            if(find_ref(i) != 1){
                t = false;
                break;
            }
        }
        if(t) break;
        ref = next_ref;
    }
    
    
    for(char x: v) ref[x -'a'] = 0;

    
    for(char c: s){
        if(ref[c-'a'] == 1) cout << char(c + 'A' - 'a');
        else cout << c;
    }
    cout << endl;
}