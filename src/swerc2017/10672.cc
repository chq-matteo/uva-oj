#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> e[10002];
int p[10002];
int m[10002];
int h[10002];
int c[10002];

deque<int> leaf;
long long ans = 0;

int main() {
    int n, v, d;
    while (cin >> n and n) {
        ans = 0;
        leaf.clear();
        for (int i = 0; i < n; i++) {
            p[i + 1] = -1;
            m[i + 1] = 0;
            h[i + 1] = -1;
            c[i + 1] = 0;
            e[i+1].clear();
        }
        int q;
        for (int i = 0; i < n; i++) {
            cin >> v;
            cin >> m[v] >> d;
            for (int j = 0; j < d; j++) {
                cin >> q;
                p[q] = v;
                e[v].push_back(q);
            }
            if (d == 0)
                leaf.push_back(v);
        }
        while (!leaf.empty()) {
            int top = leaf.front();
            leaf.pop_front();
            
            ans += abs(m[top] - 1);
            // cout << "ans: " << ans << " at: " << top << endl;
            if (p[top] != -1) {
                m[p[top]] += (m[top] - 1);
                m[top] = 1;
                c[p[top]]++;
                if (c[p[top]] == e[p[top]].size()) {
                    leaf.push_back(p[top]);
                }
            }
        }
        cout << ans << '\n';
    }
}