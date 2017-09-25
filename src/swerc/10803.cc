#include <iostream>
#include <queue>
#include <math.h>

using namespace std;
int inf = 2000000000;
struct r {
    int t;
    double c;
    friend bool operator<(r a, r b) {
        return a.c > b.c;
    }
};
struct c {
    int x, y;
};
c city[102];
double dist(int i, int j) {
    return sqrt((city[i].x - city[j].x) * (city[i].x - city[j].x) + (city[i].y - city[j].y) * (city[i].y - city[j].y));
}
double v[102][102];
deque<r> t[102];
int main() {
    int T, n, x, y;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            t[i].clear();
            for (int j = 0; j < n; j++) {
                v[i][j] = inf;
            }
        }
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            city[i] = {x, y};
            for (int j = 0; j < i; j++) {
                double d = dist(i, j);
                if (d <= 10) {
                    // cout << d << '\n' << i << j;
                    t[i].push_back({j, d});
                    t[j].push_back({i, d});
                }
            }
        }
        // dijkstra
        double ans = 0;
        bool send = false;
        for (int i = 0; i < n; i++) {
            v[i][i] = 0;
            priority_queue<r> p;
            p.push({i, 0});
            while(!p.empty()) {
                r top = p.top();
                p.pop();
                for (auto& g : t[top.t]) {
                    if (top.c + g.c < v[i][g.t]) {
                        v[i][g.t] = top.c + g.c;
                        p.push({g.t, v[i][g.t]});
                    }
                }
            }
            for (int j = 0; j < n; j++) {
                if (v[i][j] > inf - 10) {
                    // cout << v[i][j] << ' ' << i << ' ' << j << '\n';
                    // send timmy
                    i = n;
                    send = true;
                    break;
                }
                else {
                    ans = max(ans, v[i][j]);
                }
            }
        }
        cout << "Case #" << tc+1 << ":\n";
        if (send) {
            cout << "Send Kurdy\n";
        }
        else {
            printf("%.4lf\n", ans);
        }
        cout << '\n';
    }
}