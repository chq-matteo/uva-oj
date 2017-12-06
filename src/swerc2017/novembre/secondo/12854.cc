#include <iostream>
using namespace std;
int x[5];
int y[5];
int main() {
    int i = 0;
    while (cin >> x[i++]) {
        while (i < 5) {
            cin >> x[i++];
        }
        i = 0;
        while (i < 5) {
            cin >> y[i++];
        }
        i = 0;
        bool ans = true;
        for (int i = 0; i < 5; i++) {
            ans &= x[i] ^ y[i];
        }
        cout << (ans ? "Y\n" : "N\n");
    }
}