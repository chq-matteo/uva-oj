#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
const int mn = 50005;
vector<int> m[mn];
int x[mn];
int y[mn];
struct xy {
    int x, y;
};
xy p[mn];
float ds[mn];
float dist(int a, int b) {
    return hypot((p[a].x - p[b].x), (p[a].y - p[b].y));
}
bool ord(xy a, xy b) {
    return hypot(a.x, a.y) < hypot(b.x, b.y);
}
int v[mn];
vector<int> coda;
int bicolor(int id) {
    coda.clear();
    coda.push_back(id);
    int black = 1;
    int white = 0;
    v[id] = 1;
    while (!coda.empty()) {
        int top = coda.back();
        coda.pop_back();
        for (auto& node : m[top]) {
            if (!v[node]) {
                v[node] = -v[top];
                if (v[node] == 1) {
                    black++;
                }
                else {
                    white++;
                }
                coda.push_back(node);
            }
        }
    }
    // cout << white << ' ' << black << endl;
    return min(white, black);
}
int main() {
    int n;
    ios::sync_with_stdio(false);
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            v[i] = 0;
            m[i].clear();
            cin >> p[i].x >> p[i].y;
            //for (int j = 0; j < i; j++) {
            //    // cout << dist(i, j) << endl;
            //    if (dist(i, j) <= 5) {
            //        m[i].push_back(j);
            //        m[j].push_back(i);
            //    }
            //}
        }
        int min_b = 0;
        sort(p, p+n, ord);
        for (int i = 0; i < n; i++) {
            ds[i] = hypot(p[i].x, p[i].y);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                // cout << dist(i, j) << endl;
                if (dist(i, j) <= 5) {
                    m[i].push_back(j);
                    m[j].push_back(i);
                }
                if (ds[j] - ds[i] > 5.1) {
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                min_b += bicolor(i);
                // // cout << i << '\n';
            }
        }
        cout << min_b << '\n';    
    }
}