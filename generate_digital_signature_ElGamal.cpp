#include <iostream>

using namespace std;

int mod_exp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    int q, alpha, XA, k, H_M;
    cin >> q >> alpha >> XA >> k >> H_M;

    int s1 = mod_exp(alpha, k, q);
    int k_inv = mod_exp(k, q - 2, q - 1);
    int s2 = (k_inv * (H_M - XA * s1)) % (q - 1);
    if (s2 < 0) s2 += (q - 1);
    
    cout << "s1=" << s1 << endl;
    cout << "s2=" << s2 << endl;

    int v1 = mod_exp(alpha, H_M, q);
    int v2 = (mod_exp(s1, s2, q) * mod_exp(mod_exp(alpha, XA, q), s1, q)) % q;

    cout << "v1=" << v1 << endl;
    cout << "v2=" << v2 << endl;

    return 0;
}
