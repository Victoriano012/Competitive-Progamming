#include <iostream>

using namespace std;

typedef long long ll;

ll pow(int n){
  if(n == 0) return 1;
  ll k = pow(n/2);
  if(n % 2 == 0) return k*k;
  return k*k*2;
}

int main(){
  int n;
  for(int n = 1; n < 100; n++){
    long long k = pow(n-1);
    cout << k*k*2+k-1 << endl;
  }
  cin >> n;
}