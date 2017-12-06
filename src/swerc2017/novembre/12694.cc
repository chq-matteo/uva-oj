#include <iostream>
#include <algorithm>
using namespace std;
struct sf {
    int s, f;
};
bool ord(sf a, sf b) {
    return a.f < b.f;
}
sf t[100];
int main() {
    int n;
    int e;
    cin >> n;
    for (int tc = 0; tc < n; tc++) {
        e = 0;
        while (cin >> t[e].s and cin >> t[e].f and t[e].s + t[e].f != 0) {
            e++;
        }
        sort(t, t+e, ord);
        int p = 0;
        int ans = 0;
        for (int i = 0; i < e; i++) {
            if (t[i].s >= p) {
                p = t[i].f;
                ans += 1;
            }
        }
        cout << ans << '\n';
    }
}