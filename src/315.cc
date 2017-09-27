// 315 Network 
//Finding Articulation Points/Bridges Graph Traversal
#include <iostream>
#include <vector>
#include <set>
#include <sstream>
using namespace std;
vector<int> e[102];
// the lowest 
int m[102];
// the first
int s[102];
// critical
bool c[102];
int pr[201];
set<int> a;
int ct;
int rt;
int prt;
bool v[102];
void dfs(int n) {
    s[n] = ct++;
    m[n] = ct;
    for (auto& t : e[n]) {
        // if not visited
        if (s[t] == -1) {
            if (n == rt)
                prt++;
            pr[t] = n;
            dfs(t);

            if (m[t] >= s[n]) {
                a.insert(n);
            }
            m[n] = min(m[n], m[t]);
        }
        else if (t != pr[n]) {
            m[n] = min(m[n], s[t]);
        }
    }
}
int main() {
    int n, t, f, p;
    while (cin >> n && n) {
        a.clear();
        for (int i = 0; i < n; i++) {
            m[i] = 0;
            s[i] = -1;
            v[i] = false;
            e[i].clear();
            pr[i] = 0;
        }
        while (cin >> f && f) {
            f--;
            string s;
            getline(cin,  s);
            istringstream ss(s.c_str());
            while (ss >> t) {
                t--;
                e[f].push_back(t);
                e[t].push_back(f);
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == -1) {
                prt = 0;
                rt = i;
                dfs(i);
                if (prt <= 1) {
                    auto g = a.find(i);
                    if (g != a.end())
                        a.erase(i);
                }
            }
        }
        cout << a.size() << '\n';
    }
}