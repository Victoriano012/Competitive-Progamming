#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    while (cin >> s){
    	int a = 0, b = 0, c = 0, d = 0;
    	for (char ch : s){
    		switch(ch){
    			case 'a': a++; break;
    			case 'b': b++; break;
    			case 'c': c++; break;
    			case 'd': d++; break;
    		}
    	}
    	if (abs(a+b-c-d) > 1 || b > d+1 || c > a+1){
    		cout << "NO" << '\n';
    		continue;
    	}
    	if (b == d+1){
    		if (a+c>0){
    			cout << "NO" << '\n';
    			continue;
    		}
    		else{
    			for (int i = 0; i < d; i++)
    				cout << "bd";
    			cout << 'b' << '\n';
    			continue;
    		}
    	}
    	if (c == a+1){
    		if (b+d>0){
    			cout << "NO" << '\n';
    			continue;
    		}
    		else{
    			for (int i = 0; i < a; i++)
    				cout << "ca";
    			cout << 'c' << '\n';
    			continue;
    		}
    	}
    	if (a == c){
    		if (b == d){
    			for (int i = 0; i < d; i++)
    				cout << "bd";
    			for (int i = 0; i < a; i++)
    				cout << "ac";
    			cout << '\n';
    			continue;
    		}
    		else{
    			for (int i = 0; i < a; i++)
    				cout << "ca";
    			for (int i = 0; i < b; i++)
    				cout << "db";
    			cout << 'd' << '\n';
    			continue;
    		}
    	}
    	if (1+a+b==c+d){
    		for (int i = 0; i < c; i++)
    			cout << "ca";
    		for (int i = 0; i < a-c; i++)
    			cout << "da";
    		for (int i = 0; i < d+c-a-1; i++)
    			cout << "db";
    		cout << 'd' << '\n';
    		continue;
    	}
    	if (a == c+d+1){
    		for (int i = 0; i < c; i++)
    			cout << "ac";
    		for (int i = 0; i < d; i++)
    			cout << "ad";
    		cout << 'a' << '\n';
    		continue;
    	}
    	for (int i = 0; i < c; i++)
    		cout << "ac";
    	if (a > 0)
    		cout << 'a';
    	for (int i = 0; i < a-c-1; i++)
    		cout << "da";
    	for (int i = 0; i < d-a+c; i++)
    		cout << "db";
    	if (d > 0)
    		cout << 'd';
    	if (b > d-a+c && b > 0)
    		cout << 'b';
    	cout << '\n';
    }
	return 0;
}