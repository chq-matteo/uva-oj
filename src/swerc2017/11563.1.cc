#include <iostream>
#include <queue>
#include <set>
using namespace std;
struct mr {
    int use;
    int v;
    friend bool operator<(mr a, mr b) {
        if (a.use > b.use) return true;
        else if (a.use == b.use) return a.v < b.v;
        return false;
    }
};
int e[100001];
vector<int> f[100001];
priority_queue<mr> cache;
int main() {
    int c, n, a;
    while (cin >> c) {
        cin >> n >> a;
        for (int i = 0; i < n; i++) {
            f[i].clear();
        }
        for (int i = 0; i < a; i++) {
            cin >> e[i];
            f[e[i]].push_back(i);
        }
        for (int i = 0; i < c; i++) {
            cache.push({100000000, -1});
        }
        for (int i = 0; i < a; i++) {
            mr top = cache
        }
        cout << ans << '\n';
    }
}