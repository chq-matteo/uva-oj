#include <iostream>
#include <vector>
#include <algorithm>
// 10765 Doves and Bombs
// Finding Articulation Points/Bridges
using namespace std;
vector<int> r[10001];
int pigeon[10001];
int dfs_num[10001];
int dfs_low[10001];
int dfs_parent[10001];
int sorted[100001];
bool comp(int a, int b) {
    if (pigeon[a] > pigeon[b])
        return true;
    else if (pigeon[a] == pigeon[b])
        return a < b;
    return false;
}
int df = 0;
int rchild = 0;
int dfs(int n) {
    dfs_num[n] = df++;
    dfs_low[n] = dfs_num[n];
    for (auto& g : r[n]) {
        if (dfs_num[g] == -1) {
            dfs_parent[g] = n;
            dfs(g);
            if (n == 0)
                rchild++;
            if (dfs_low[g] >= dfs_num[n]) {
                pigeon[n]++;
            }
            dfs_low[n] = min(dfs_low[n], dfs_low[g]);
        }
        else if (g != dfs_parent[n]) {
            dfs_low[n] = min(dfs_low[n], dfs_num[g]);
        }
    }
}
int main() {
    int n, m, x, y;
    while (cin >> n >> m and n+m != 0) {
        for (int i = 0; i < n; i++) {
            dfs_low[i] = -1;
            dfs_num[i] = -1;
            dfs_parent[i] = -1;
            r[i].clear();
            pigeon[i] = 0;
            sorted[i] = i;
        }
        while (cin >> x >> y and x+y != -2) {
            r[x].push_back(y);
            r[y].push_back(x);
        }
        df = 0;
        rchild = 0;
        dfs(0);
        pigeon[0]--;
        pigeon[0] = max(0, pigeon[0]);
        sort(sorted, sorted + n, comp);
        for (int i = 0; i < m; i++) {
            cout << sorted[i] << ' ' << pigeon[sorted[i]]+1 << '\n';
        }
        cout << '\n';
    }
}