#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int modInverse(int e, int phi_n) {
    int d = 1;
    while ((e * d) % phi_n != 1) {
        d++;
    }
    return d;
}

int modExp(int base, int exp, int mod) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result = (result * base) % mod;
    }
    return result;
}

int main() {
    // Variables for inputs
    int m, p, q, e;
    cin >> m >> p >> q >> e;
    int n = p * q;
    int phi_n = (p - 1) * (q - 1); 
    int d = modInverse(e, phi_n);
    int CT = modExp(m, e, n);
    int PT = modExp(CT, d, n);
    cout << "Cipher text is " << CT << endl;
    cout << "Plain Text is " << PT << endl;

    return 0;
}
