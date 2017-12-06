/*
908 Re-connecting Computer Sites
Minimum Spanning Tree
Just compute the length of the minimum spanning tree
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int g[1000010];
int d[1000010];
struct lane {
    int a, b;
    long long c;
    friend bool operator<(lane x, lane y) {
        return x.c < y.c;
    }
};
struct pa {
    int r, d;
};
vector<lane> orig;
vector<lane> ne;
vector<lane> nk;
int get(int i) {
    if (g[i] == i) {
        return i;
    }
    else {
        g[i] = get(g[i]);
        return g[i];
    }
}
int main() {
    ios::sync_with_stdio(false);
    int n, t, k, m, a, b;
    long long c;
    bool fs = true;
    while(cin >> n) {
        if (fs) fs = false;
        else cout << '\n';

        long long prev = 0;
        ne.clear();
        nk.clear();
        orig.clear();
        for (int i = 1; i <= n; i++) {
            g[i] = i;
            d[i] = 1;
        }
        for (int i = 0; i < n-1; i++) {
            cin >> a >> b >> c;
            prev += c;
        }
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> a >> b >> c;
            nk.push_back({a, b, c});
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            ne.push_back({a, b, c});
        }
        for (auto& l : nk) {
            ne.push_back(l);
        }
        sort(ne.begin(), ne.end());
        long long nex = 0;
        for (auto& l : ne) {
            if (get(l.a) != get(l.b)) {
                nex += l.c;
                if (d[l.a] > d[l.b]) {
                    g[get(l.a)] = g[get(l.b)];
                    d[get(l.a)] = max(d[get(l.a)], d[get(l.b)] + 1);
                }
                else {
                    g[get(l.b)] = g[get(l.a)];
                    d[get(l.b)] = max(d[get(l.b)], d[get(l.a)] + 1);
                }
            }
        }
        bool can = true;
        int last = get(1);
        for (int i = 1; i <= n; i++) {
            if (get(i) != last) can = false;
        }
        cout << prev << '\n' << (can ? min(nex, prev) : prev) << '\n';
    }
}