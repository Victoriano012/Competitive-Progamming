#include <iostream>
#include <vector>

using namespace std;

int main(){
    cout.setf(ios::fixed);
    cout.precision(3);
    vector<double> v(6);
    double maxim = 0, suma = 3.5;
    for(double i = 0; i < 6; i++){
        cin >> v[i];
        maxim = max(v[i], maxim);
        suma -= (i+1)*v[i];
    }
    suma = abs(suma);
    cout << suma/maxim << endl;
}