#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

int modInverse(int a, int p) {
    a = a % p;
    for(int i = 1; i < p; i++) {
        if ((a*i) % p == 1) {
            return i;
        }
    }
    return -1;
}

void addEllipticCurve(int p, int a, int x1, int y1, int x2, int y2) {
    if(x1 == x2 && y1 == y2) {
        int lambda_num = (3 * x1 * x1 + a) % p;
        int lambda_d = modInverse(2 * y1, p);
        int lambda = (lambda_num * lambda_d) % p;
        int x3 = (lambda * lambda - 2 * x1) %p;
        if(x3 < 0) {
            x3 += p;
        }
        int y3 = (lambda * (x1 - x3) - y1) % p;
        if(y3 < 0) {
            y3 += p;
        }
        cout << x3 << " " << y3 << endl;
    } else {
        int lambda_num = (y2 - y1) % p;
        if(lambda_num < 0) {
            lambda_num += p;
        }
        int lambda_d = modInverse(x2 - x1, p);
        int lambda = (lambda_num * lambda_d) % p;
        int x3 = (lambda * lambda - x1 - x2) % p;
        if(x3 < 0) {
            x3 += p;
        }
        int y3 = (lambda * (x1 - x3) - y1) % p;
        if(y3 < 0) {
            y3 += p;
        }
        cout << x3 << " " << y3 << endl;
    }
}

int main() {
    int p, a, b, x1, y1, x2, y2;
    cin >> p >> a >> b >> x1 >> y1 >> x2 >> y2;
    addEllipticCurve(p, a, x1, y1, x2, y2);
    return 0;
}