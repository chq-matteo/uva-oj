#include <iostream>
#include <cstring>
using namespace std;
long long bc[60][60][60];
long long BC(long long n, long long k, long long m) {
    if (n < 0) return 0;
    if (k == 0) {
        if (n != 0) return 0;
    }
    if (bc[n][k][m] != -1) return bc[n][k][m];
    long long ans = 0;
    for (long long i = 1; i <= m; i++) {
        ans += BC(n - i, k - 1, m);
    }
    bc[n][k][m] = ans;
    return ans;
}
int main() {
    long long n, k, m;
    memset(bc, -1, sizeof(bc));
    for (int i = 0; i < 60; i++) {
        bc[0][0][i] = 1;
    }
    while(cin >> n) {
        cin >> k >> m;
        cout << BC(n, k, m) << '\n';
    }
}