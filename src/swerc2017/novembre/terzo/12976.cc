#include <iostream>
#include <algorithm>
using namespace std;
struct mt {
    double s, p;
};

bool ord(mt a, mt b) {
    if (a.s == b.s) return a.p < b.p;
    return a.s < b.s;
}
mt m[100005];
int main() {
    int n, k;
    int tc = 0;
    while (cin >> n >> k and n + k) {
        tc++;
        for (int i = 0; i < n; i++) {
            cin >> m[i].s >> m[i].p;
        }
        sort(m, m+n, ord);
        double s = 0;
        for (int i = 0; i < k - 1; i++) {
            s += m[i].s;
        }
        double ans = (s + m[k - 1].s) * m[k - 1].p / m[k - 1].s;
        for (int i = k; i < n; i++) {
            ans = min(ans, (s + m[i].s) * m[i].p / m[i].s);
        }
        printf("Case #%d: %.6lf\n", tc, ans);
    }
}