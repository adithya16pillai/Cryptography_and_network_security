#include <iostream>
using namespace std;

int extendedGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

int modInverse(int a, int m) {
    int x, y;
    int gcd = extendedGCD(a, m, x, y);
    if (gcd != 1) {
        return -1;
    }
    int result = (x % m + m) % m;
    return result;
}

int main() {
    int a, m;
    cin >> a >> m; //Enter values for a and m:
    int inverse = modInverse(a, m);
    if (inverse == -1) {
        cout << "Inverse doesn't exist." << endl;
    } else {
        cout << inverse << endl; //The modular multiplicative inverse is
    }
    return 0;
}
