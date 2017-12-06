#include <iostream>
using namespace std;
int main() {
    int t, m, n, r, c;
    cin >> t;
    string g = "Gretel\n";
    string h = "Hansel\n";
    for (int i = 0; i < t; i++) {
        cin >> m >> n >> r >> c;
        m--;
        n--;
        if (m % 2 == 0) {
            if (n % 2 == 0) {
                cout << h;
            }
            else {
                cout << g;
            }
        }
        else {
            if (n % 2 == 0) {
                cout << g;
            }
            else {
                cout << h;
            }
        }
    }
}