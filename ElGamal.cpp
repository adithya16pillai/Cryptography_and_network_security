#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while(exp > 0) {
        if(exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base*base) % mod;
    }
    return result;
}

long long mod_inverse(long long a, long long m) {
    a = a % m;
    for(int x = 1; x < m; x++) {
        if((a*x) % m == 1) {
            return x;
        }
    }
    return 1;
}

int main() {
    long q, r, m, a, b;
    cin >> q >> r >> m >> a >> b;
    long long A = mod_exp(r, a, q);
    cout << "Public key of Alice:" << A << endl;
    long long B = mod_exp(r, b, q);
    cout << "Public key of Bob: " << B << endl;
    int c1 = mod_exp(r, b, q);          
    int c2 = (m * mod_exp(A, b, q)) % q; 
    cout << "Cipher text is " << m << endl; 
    int s = mod_exp(c1, a, q);             
    int s_inv = mod_exp(s, q-2, q);       
    int PT = (c2 * s_inv) % q;            
    cout << "Plain Text is " << PT << endl; 
}