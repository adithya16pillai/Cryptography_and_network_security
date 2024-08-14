#include <iostream>
using namespace std;

int modularExponentiation(int base, int exp, int mod) {
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
    int base, exp, mod;
    cin >> base; // Enter base
    cin >> exp; //Enter Exponent
    cin >> mod; //Enter modulus
    int result = modularExponentiation(base, exp, mod);
    cout << result << endl; //result
    return 0;
}
