// 11231 Black and white painting finding patterns harder
// focus on the lower left tile
#include <iostream>
using namespace std;
int main() {
    int n, m, c;
    while (cin >> n >> m >> c and n + m + c) {
        cout << ((n - 7) * (m - 7) / 2 + ((((n - 7) * (m - 7)) % 2) & c)) << '\n';
    }
}