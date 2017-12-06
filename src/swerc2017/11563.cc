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
deque<int> f[100001];
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
        for (int i = 0; i < n; i++) {
            f[i].push_back(10000000);
        }
        set<mr> pq;
        set<int> el;
        for (int i = 0; i < c; i++) {
            pq.insert({10000000, -i});
        }
        int ans = 0;
        for (int i = 0; i < a; i++) {
            auto g = el.find(e[i]);
            if (g != el.end()) {
                auto z = pq.find({f[e[i]].front(), e[i]});
                // cout << "was there " << z->v << ' ' << z->use << endl;
                pq.erase(z);
                f[e[i]].pop_front();
                pq.insert({f[e[i]].front(), e[i]});
            }
            else {
                auto z = pq.begin();
                // cout << "the uselest " << z->v << ' ' << z->use << endl;
                ans++;
                auto ll = el.find(z->v);
                if (ll != el.end())
                   el.erase(ll);
                pq.erase(z);
                f[e[i]].pop_front();
                pq.insert({f[e[i]].front(), e[i]});
                el.insert(e[i]);
            }
        }
        cout << ans << '\n';
    }
}