#include <iostream>
#include <tuple>
#include <cmath>
#include <string.h>
using namespace std;

int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1)
        return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;

    return x1;
}

tuple<int, int> pointAddition(int x1, int y1, int x2, int y2, int a, int q) {
    if (x1 == x2 && y1 == y2) {
        int slope = (3 * x1 * x1 + a) * modInverse(2 * y1, q) % q;
        if (slope < 0)
            slope += q;
        int x3 = (slope * slope - 2 * x1) % q;
        if (x3 < 0)
            x3 += q;
        int y3 = (slope * (x1 - x3) - y1) % q;
        if (y3 < 0)
            y3 += q;
        return {x3, y3};
    } else {
        int slope = (y2 - y1) * modInverse(x2 - x1, q) % q;
        if (slope < 0)
            slope += q;
        int x3 = (slope * slope - x1 - x2) % q;
        if (x3 < 0)
            x3 += q;
        int y3 = (slope * (x1 - x3) - y1) % q;
        if (y3 < 0)
            y3 += q;
        return {x3, y3};
    }
}

tuple<int, int> scalarMultiplication(int x, int y, int k, int a, int q) {
    int xR = x, yR = y;
    for (int i = 1; i < k; i++) {
        tie(xR, yR) = pointAddition(xR, yR, x, y, a, q);
    }
    return {xR, yR};
}

int main() {
    int a, b, q;
    int Gx, Gy;
    int Pmx, Pmy;
    int PBx, PBy;
    int k;

    cin >> a >> b >> q;
    cin >> Gx >> Gy;
    cin >> Pmx >> Pmy;
    cin >> PBx >> PBy;
    cin >> k;

    int kGx, kGy;
    tie(kGx, kGy) = scalarMultiplication(Gx, Gy, k, a, q);

    int kPBx, kPBy;
    tie(kPBx, kPBy) = scalarMultiplication(PBx, PBy, k, a, q);

    int C1x = kGx, C1y = kGy;
    int C2x, C2y;
    tie(C2x, C2y) = pointAddition(Pmx, Pmy, kPBx, kPBy, a, q);

    cout << C1x << " " << C1y << endl;
    cout << C2x << " " << C2y << endl;

    return 0;
}
