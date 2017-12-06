#include <iostream>
#include <cmath>
#include <random>
using namespace std;
long long avg(long long a) {
    long long k = log(a);
    return max(k, 1ll);
}
int main() {
    long long n;
    ios::sync_with_stdio(false);
    while (cin >> n and n) {
        long long a = 1;
        long long ans = 0;
        while ((2 * n + a - 2) / (2 * a - 1) >= 2*a - 1) {
            if ((2 * n + a - 2) % (2 * a - 1) == 0) {
                // long long b = (2 * n + a - 2) / (2 * a - 1);
                // cout << a * b - ((double)(a + b) / 2.0) + 1 << ' ' << a << ' ' << b << '\n';
                ans += 2;
                if ((2 * n + a - 2) / (2 * a - 1) == 2*a - 1) {
                    ans -= 1;
                }
                a += a;
            }
            else {
                a += 1;

            }
        }
        cout << n << ' ' << ans << '\n';
    }
}