// 11130 Billiard bounces
// we unwrap the rectangle
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int a, b, v, A, s;
    while (cin >> a >> b >> v >> A >> s and a + b + v + A + s) {
        double space = v * s / 2 + 0;
        double x = space * cos(A / 180.0 * M_PI) + a/2.0;
        double y = space * sin(A / 180.0 * M_PI) + b/2.0;
        cout << (int)(x / a) << ' ' << (int)(y / b) << '\n';
    }
}