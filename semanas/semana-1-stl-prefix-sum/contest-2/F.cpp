#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int caso = 0; caso < n; caso++) {
        long long numero;
        cin >> numero;

        for (long long p = 100000000000000000LL; p >= 10; p /= 100) {

            if (numero >= p && numero < p * 10) {
                numero = p - 1;
            }

            else if (numero >= p * 10) {
                numero -= 9 * p;
            }
        }

        cout << numero << '\n';
    }

    return 0;
}