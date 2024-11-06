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
    int p, q, H_M, h, X, k;
    cin >> p >> q >> H_M >> h >> X >> k;

    int g = mod_exp(h, (p - 1) / q, p);
    int r = mod_exp(g, k, p) % q;
    int s = (H_M + X * r) * mod_exp(k, q - 2, q) % q;
    
    cout << "r=" << r << endl;
    cout << "s=" << s << endl;

    int w = mod_exp(s, q - 2, q);
    int u1 = (H_M * w) % q;
    int u2 = (r * w) % q;
    int v = (mod_exp(g, u1, p) * mod_exp(X, u2, p)) % p % q;

    cout << "w=" << w << endl;
    cout << "u1=" << u1 << endl;
    cout << "u2=" << u2 << endl;
    cout << "v=" << v << endl;

    return 0;
}
