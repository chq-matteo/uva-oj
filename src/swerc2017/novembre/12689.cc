#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100005;
bool s[maxn];
struct prime {
    uint64_t m;
    int k;
    int p;
    int pk;
};

vector<int> primes;
vector<prime> m;

bool ord(prime a, prime b) {
    if (a.m == b.m) return a.pk > b.pk;
    return a.m < b.m;
}
uint64_t mult(int p, int n) {
    uint64_t ans = 0;
    int tp = p;
    while (n/p) {
        ans += n/p;
        p *= tp;
    }
    return ans;
}

int main() {
    int n, x;
    for (int i = 0; i < maxn; i++) {
        s[i] = true;
    }
    for (int i = 2; i < maxn; i++) {
        if (s[i]) {
            primes.push_back(i);
            for (int j = i; j < maxn; j += i) {
                s[j] = false;
            }
        }
    }
    while (cin >> n >> x and n + x) {
        uint64_t ans = 0;
        m.clear();
        for (auto& p : primes) {
            // cout << "looking for " << p << endl;
            if (p > n) {
                break;
            }
            uint64_t mp = mult(p, n);
            // cout << "multiplicity of " << p << " = " << mp << endl;
            int k = 1;
            int pk = p;
            while (mp/k >= x) {
                // cout << "adding " << p << '^' << k << " with " << mp/k << endl;
                m.push_back({mp/k, k, p, pk});
                k++;
                pk *= p;
            }
        }
        sort(m.begin(), m.end(), ord);
        int kk = 0;
        int sc = 0;
        uint64_t ss = 0;
        for (int i = 0; i < m.size(); i++) {
            uint64_t s = 1ull << ((m.size() - i - 1));
            if (kk == m[i].m) {
                ss += s;
                ss >>= m[i].k - 1;
                ans >>= m[i].k - 1;
                // cout << "quante scelte " << ((ss)/ 2ull * ((ss)-1ull)) << endl;
                // ans += ((ss)/ 2ull * ((ss)-1ull));
                // ss = s;
                // kk = m[i].m;
            }
            else {
                // if (kk == 24)
                //     cout << "quante scelte " << ((ss)/ 2ull * ((ss)-1ull)) << endl;
                ans += ((ss) * ((ss)-1ull)) / 2ull;
                // cout << "doppio count " << sc << endl;
                ss = s;
                kk = m[i].m;
                ss >>= m[i].k - 1;
                ans >>= m[i].k - 1;
            }
            // if (kk == 24)
            //    cout << "summing " << m[i].p << '^' << m[i].k << " with " << s << " and multiplicity " << m[i].m << endl;   
        }
        // ans += ((ss) * ((ss)-1ull)) / 2ull;
        // ans >> sc;
        
        cout << ans << '\n';
    }

}