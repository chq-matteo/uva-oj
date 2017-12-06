#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    long long n, t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cin >> n;
        cout << "Case " << tc << ": ";
        long long ans = n * (n - 1);
        if (ans % 4 == 0) {
            cout << ans / 4 << '\n';
        }
        else if (ans % 2 == 0) {
            cout << ans / 2 << '/' << 2 << '\n';            
        }
        else {
            cout << ans << '/' << 4 << '\n';            
        }
    }
}