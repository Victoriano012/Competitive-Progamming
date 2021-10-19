#include <iostream>

using namespace std;

int num(string s, int n){
	if(n == 1) return 1;
	for(int i = 0; i < n; ++i){
		if(s[i] != '0'){
			return 1 + num(s.substr(0, (n+1)/2), (n+1)/2) + num(s.substr((n+1)/2), n/2);
		}
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while(cin >> n && n != 0){
		string s;
		cin >> s;
		cout << num(s, n) << endl;
	}

}