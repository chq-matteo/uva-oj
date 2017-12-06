#include <iostream>
using namespace std;
string z[100001];
int diff(int i, int j) {
    for (int k = 0; k < min(z[i].size(), z[j].size()); k++) {
        if (z[i][k] != z[j][k]) return k;
    }
    return min(z[i].size(), z[j].size());
}
int main() {
    int t, n, q;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> z[i];
            // cout << z[i] << '\n';
        }
        cout << "Case " << (tc+1) << ":\n";
        cin >> q;
        while (q--) {
            int i, j;
            cin >> i >> j;
            cout << diff(i-1, j-1) << '\n';
        }
    }
}