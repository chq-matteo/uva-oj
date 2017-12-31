// 10940 Throwing cards away II

#include <iostream>
using namespace std;
int log(int n) {
    for (int i = 0; ; i++) {
        if (1 << i > n) return (1 << i);
    }
}
int main() {
    int n;
    ios::sync_with_stdio(false);
    while (cin >> n and n) {
        if (n == 1) {
            cout << 1 << '\n';
        }
        else if (n == 2) {
            cout << 1 << '\n';            
        }
        else {
            cout << ((n << 1) % log(n)) << '\n';
        }
    }
}