#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

long long power(long long base, long long exp,long long mod) {
    long long result = 1;
    base = base % mod;
    while(exp>0) {
        if(exp%2 == 1) {
            result = (result*base)%mod;
        }
        exp = exp >> 1;
        base = (base*base)%mod;
    }
    return result;
}

int main() {
    long q, r, a, b;
    cin >> q >> r >> a >> b;
    long long A =power(r, a, q);
    cout << "Public key of Alice:" << A << endl;
    long long B = power(r, b, q);
    cout << "Public key of Bob:" << B << endl;
    long long sAlice = power(B, a, q);
    cout << "Secret key calculated by Alice:" << sAlice << endl;
    long long sBob = power(A, b, q);
    cout << "Secret key calculated by Bob:" << sBob << endl;
}