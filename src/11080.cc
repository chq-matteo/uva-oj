// 11080 Place the Guards
// Graph Traversal Bipartite Graph Check
// 1. There can be only one guard for each street
// 2. A single junction with no street must be guarded by a guard
#include <iostream>
#include <vector>
using namespace std;
vector<int> g[201];
int vis[201];
vector<int> stack;
int T, v, e, f, t;
int visit(int start) {
    stack.clear();
    stack.push_back(start);
    vis[start] = -1;
    int M = 0;
    int m = 1;
    while (!stack.empty()) {
        int b = stack.back();
        stack.pop_back();
        for (auto& n : g[b]) {
            if (vis[n] == 0) {
                vis[n] = -vis[b];
                if (vis[n] == -1) m++;
                else M++;
                stack.push_back(n);
            }
            else if (n != b && vis[n] == vis[b])
                return -1;
        }
    }
    return max(min(m, M), 1);
}
int main() {
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> v >> e;
        for (int i = 0; i < v; i++) {
            g[i].clear();
            vis[i] = 0;
        }
        for (int i = 0; i < e; i++) {
            cin >> f >> t;
            g[f].push_back(t);
            g[t].push_back(f);
        }
        int ans = 0;
        for (int i = 0; i < v; i++) {
            if (vis[i] == 0) {
                int value = visit(i);
                if (value == -1) {
                    ans = -1;
                    break;
                }
                ans += value;
            }
        }
        cout << ans << '\n';
    }
}