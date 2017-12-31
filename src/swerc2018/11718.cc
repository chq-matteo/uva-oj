// finding pattern harder 11718 Fantasy of a Summation
#include <iostream>
using namespace std;
// squinting your eyes a bit you can see that calling S = sum(A)
// then s = S(1 + n + n^2 + n^3 + ... + n^(k-1))
int modpow(int n, int k, int mod) {
    // also power by squaring
    int ans = 1;
    int p = n;
    n = n % mod;
    int i = 0, j = 1;
    while (i < k) {
        if (j & k) {
            i += j;
            ans = (ans * p) % mod;
        }
        p = (p * p) % mod;
        j *= 2;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    long long T, n, k, mod;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> n >> k >> mod;
        long long accumulator = 0;
        long long tmp = 0;
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            accumulator = (accumulator + tmp) % mod;
        }
        cout << "Case " << i << ": " << (int)(((modpow(n, k - 1, mod)) * k * accumulator) % mod) << "\n";
    }
}