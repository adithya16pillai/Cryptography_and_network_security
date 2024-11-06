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
    int p, q, e, w;
    cin >> p >> q >> e >> w;

    int n = p * q;
    int phi_n = (p - 1) * (q - 1);

    int d = 1;
    while ((d * e) % phi_n != 1) {
        d++;
    }

    int s = mod_exp(w, d, n);
    cout << "s=" << s << endl;

    int w_calculated = mod_exp(s, e, n);
    cout << "w calculated from s =" << w_calculated << endl;

    return 0;
}
