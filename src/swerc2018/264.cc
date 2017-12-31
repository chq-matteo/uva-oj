// 264 Count on Cantor
#include <iostream>
using namespace std;
int main() {
    long long n;
    while (cin >> n) {
        // k * (k + 1) / 2 <= n <= (k + 1)(k + 2) / 2
        // k * (k + 1) <= 2n <= (k + 1)(k + 2)
        // k^2 + k <= 2n <= k^2 + 2k + 1 + k + 1
        // we are left to compute such k
        // well actually binary search works as well
        long long h, l, m;
        h = 2 * n;
        l = 0;
        while (h - l > 1) {
            m = l + (h - l) / 2;
            if (m * m + m < 2*n) {
                l = m;
            }
            else {
                h = m;
            }
        }
        
        long long d = n - l * (l +  1) / 2;
        l++;
        // now is it going up or down the diagonal
        if (l % 2 == 0) {
            // its going down
            printf("TERM %lld IS %lld/%lld\n", n, d, l - d + 1);
        }
        else {
            printf("TERM %lld IS %lld/%lld\n", n, l - d + 1, d);
        }
    }
}