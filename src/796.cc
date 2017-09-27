#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct edge {
    int a, b;
    friend bool operator<(edge x, edge y) {
        if (x.a == y.a && x.b == y.b) return false;
        if (x.a < y.a) return true;
        if (x.a == y.a && x.b < y.b) return true;
        return false;
    }
};
const int NODE = 10000;
const int NON_VISITED = -1;
int low[NODE];
int num[NODE];
int parent[NODE];
vector<int> e[NODE];
int N = 0;
char p;
set<edge> crit;
int dfs(int n) {
    N++;
    low[n] = N;
    num[n] = N;
    for (auto& m : e[n]) {
        if (low[m] == NON_VISITED) {
            parent[m] = n;
            dfs(m);

            if (low[m] > num[n]) {
                crit.insert({min(m, n), max(m, n)});
            }
            low[n] = min(low[n], low[m]);
        }
        else if (m != parent[n]) {
            low[n] = min(low[n], num[m]);
        }
    }
}
int main() {
    int n, s, c, d;
    bool fst = true;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            e[i].clear();
            low[i] = NON_VISITED;
            num[i] = NON_VISITED;
            parent[i] = 0;
        }
        crit.clear();
        for (int i = 0; i < n; i++) {
            cin >> s;
            cin >> p >> d >> p;
            for (int j = 0; j < d; j++) {
                cin >> c;
                e[s].push_back(c);
                e[c].push_back(s);
            }
        }
        // loop all connected components
        for (int i = 0; i < n; i++) {
            // setup
            if (low[i] != NON_VISITED) {
                continue;
            }
            N = 0;
            // dfs
            dfs(i);
            
        }
        printf("%d critical links\n", (int)crit.size());
        for (auto& g : crit) {
            printf("%d - %d\n", g.a, g.b);
        }
        printf("\n");
    }
}