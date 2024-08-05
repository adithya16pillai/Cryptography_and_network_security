#include <iostream>
#include <vector>
#include <numeric>

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

int findMinX(const vector<int>& num, const vector<int>& rem, int k) {
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];
    int result = 0;
    for (int i = 0; i < k; i++) {
        int pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }
    return result % prod;
}

int main() {
    const int k = 3; 
    vector<int> num(k), rem(k);
    for (int i = 0; i < k; i++) {
        cout << i + 1 << i + 1 ; // Enter a and k (space seperated)
        cin >> rem[i] >> num[i];
    }
    int x = findMinX(num, rem, k);
    cout <<  x << endl; //The smallest x that satisfies all the given congruences
    return 0;
}
