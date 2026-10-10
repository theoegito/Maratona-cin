#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;

    vector<pair<long long, int>> lista_num;
    for (int i = 0; i < n; ++i) {
        long long numero;
        cin >> numero;
        lista_num.push_back({numero, i + 1});
    }
    sort(lista_num.begin(), lista_num.end());

    for (int j = 0; j + 2 < n; ++j) {
        int l = j + 1;
        int r = n - 1;

        while (l < r) {
            long long soma = lista_num[j].first
                           + lista_num[l].first
                           + lista_num[r].first;

            if (soma == x) {
                cout << lista_num[j].second << ' '
                     << lista_num[l].second << ' '
                     << lista_num[r].second << '\n';
                return 0;
            }
            if (soma < x) ++l;
            else --r;
        }
    }
    cout << "IMPOSSIBLE\n";
}
