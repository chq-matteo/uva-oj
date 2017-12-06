#include <iostream>
#include <set>
#include <vector>
using namespace std;
struct fib {
    int v;
    int id;
    friend bool operator<(fib a, fib b) {
        return a.v < b.v;
    }
};
set<fib> f;
vector<int> ns;
int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n;
    int a = 1;
    int b = 1;
    int c = 0;
    int k = 0;
    f.insert({-a, k});
    while (true) {
        m = b;
        b = a;
        a = b + m;
        k++;
        f.insert({-a, k});
        if (a > 100000000) break;
    }
    for (int i = 0; i < n; i++) {
        cin >> c;
        cout << c << " = ";
        ns.clear();
        while (c) {
            auto g = f.lower_bound({-c, 0});
            c += g->v;
            ns.push_back(g->id);
        }
        for (int i = 0; i < ns.size(); i++) {
            cout << '1';
            if (i != ns.size() - 1)
                for (int j = ns[i]; j > ns[i+1] + 1; j--) {
                    cout << '0';
                }
            else {
                for (int j = ns[i]; j > 0; j--) {
                    cout << '0';
                }
            }
        }
        cout << " (fib)\n";
    }
}