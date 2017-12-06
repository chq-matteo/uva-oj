#include <iostream>
using namespace std;
const int maxn = 500005;
long long s[maxn];
int main() {
    ios::sync_with_stdio(false);
    int t, n, x;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
    }
}