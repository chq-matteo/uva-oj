#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct p {
    double x, y;
};
p h[100];
p g[100];
double ans[100];
double dist(p a, p b) {
    return hypot(a.x - b.x, a.y - b.y);
}
int main() {
    int N, m, n, k;
    double x, y;
    cin >> N;
    for (int t = 0; t < N; t++) {
        cin >> m >> n >> k;
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            g[i] = {x, y};
        }
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            h[i] = {x, y};
        }
        for (int i = 0; i < m; i++) {
            ans[i] = -1;
            for (int j = 0; j < n; j++) {
                if (ans[i] == -1)
                    ans[i] = dist(g[i], h[j]);
                else
                    ans[i] = min(dist(g[i], h[j]), ans[i]);
            }
        }
        sort(ans, ans + m);
        if (k == 0)
            st = 0;
        else
        printf("Case #%d:\n%.3lf\n", st);
    }
}