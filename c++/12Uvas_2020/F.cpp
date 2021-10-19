#include <iostream>
#include <string>

using namespace std;

bool capicua(string s){
	int l = s.length();
	while(s[l-1] == '0') --l;
	for(int i = 0; i < l/2; ++i) if(s[i] != s[l-i-1]) return false;
	return true;
}

string bin(long long n){
	if(n == 0) return "0";
	if(n == 1) return "1";
	if(n%2 == 0) return bin(n/2) + "0";
	return bin(n/2) + "1";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	while(cin >> n && n != 0){
		if(capicua(bin(n))) cout << "SI" << endl;
		else cout << "NO" << endl;
	}
}