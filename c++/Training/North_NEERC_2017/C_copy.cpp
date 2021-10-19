#include <iostream>
#include <vector>

using namespace std;

vector<char> v = {'a', 'e', 'i', 'o', 'u', 'y', 'w'};

bool vowel(char c){
    for(char x: v) if(c == x) return true;
    return false;
}

vector<bool> r('z'-'a'+1, false);
vector<vector<int>> con('z'-'a'+1, vector<int>('z'-'a'+1, 0));

int count(){
    int Ans = 0;
    for(int i = 0; i < 'z'-'a'; ++i){
        for(int j = i+1; j <= 'z'-'a'; ++j){
            if(r[i] != r[j]) Ans += con[i][j];
        }
    }
    return Ans;
}

pair<int, vector<bool>> create(int n){
    if(n == -1){
        return make_pair(count(), r);
    }

    for(char c: v) if(n+'a' == c) return create(n-1);
    auto k = create(n-1);
    r[n] = !r[n];
    auto k2 = create(n-1);
    if(k.first > k2.first) return k;
    return k2;
}


int main(){
    freopen("consonant.in", "r", stdin);
    freopen("consonant.out", "w", stdout);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    string s;
    cin >> s;
    int l = s.length();

    for(int i = 0; i < l-1; i++){
        if(!vowel(s[i]) && !vowel(s[i+1])){
            ++con[min(s[i], s[i+1])-'a'][max(s[i], s[i+1])-'a'];
        }
    }


    auto ref = create('z'-'a');

    
    for(char c: s){
        if(ref.second[c-'a']) cout << char(c + 'A' - 'a');
        else cout << c;
    }
    cout << endl;
}