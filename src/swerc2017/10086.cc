#include <iostream>
#include <cstring>
using namespace std;
int m[40];
int c[40][40][2];
int cost[301][301][40];
int n;
int inf = 3000*40;
int ans[301][301][40];

int mcost(int t1, int t2, int k) {
    if (t1 < 0 or t2 < 0) return inf;
    if (cost[t1][t2][k] != -1) {
        // cout << t1 << ' ' << t2 << ' ' << k << endl;
        // cout << cost[t1][t2][k] << '\n';
        return cost[t1][t2][k];
    }
    if (k == n) {
        if (t1 == 0 and t2 == 0) {
            return 0;
        }
        else {
            return inf;
        }
    }
    int t = inf;
    for (int i = 0; i <= m[k]; i++) {
        int cand = c[k][i][0] + c[k][m[k] - i][1] + mcost(t1 - i, t2 - (m[k] - i), k+1);
        if (cand < t) {
            t = cand;
            ans[t1][t2][k] = i;
            // cout << t1 << ' ' << t2 << ' ' << i << endl;
        }
    }
    cost[t1][t2][k] = t;
    return t;
}
int main() {
    int t1, t2;
    while (cin >> t1 >> t2 and t1+t2) {
        cin >> n;
        memset(c, -1, sizeof(c));
        memset(cost, -1, sizeof(cost));
        for (int i = 0; i < n; i++) {
            cin >> m[i];
            c[i][0][0] = 0;
            c[i][0][1] = 0;
            for (int j = 1; j <= m[i]; j++) {
                cin >> c[i][j][0];
            }
            for (int j = 1; j <= m[i]; j++) {
                cin >> c[i][j][1];
            }
        }
        cout << mcost(t1, t2, 0) << '\n';
        for (int i = 0; i < n; i++) {
            if (i != 0) cout << ' ';
            int a = ans[t1][t2][i];
            cout << a;
            // cout << t1 << ' ' << t2 << endl;
            t1 -= a;
            t2 -= (m[i] - a);
        }
        cout << '\n';
        cout << '\n';
        
        // coinchange bi dimensionale

    }
}