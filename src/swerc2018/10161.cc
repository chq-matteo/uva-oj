// finding patterns harder 10161 Ant on a Chessboard
#include <iostream>
#include <cmath>
using namespace std;
struct point {
    int x, y;
};
// we know when she was at time i^2 then we simulate till n
point position(int t) {
    point pos;
    int i = (int) sqrt(t);
    t -= i * i;
    if (i % 2 == 0) {
        if (t == 0) {
            return {i, 1};
        }
        else if (t < i + 1) {
            return {i + 1, 1 + t - 1};
        }
        else {
            return {i + 1 - (t - (i + 1)), 1 + i};
        }
    }
    else {
        if (t == 0) {
            return {1, i};
        }
        else if (t < i + 1) {
            return {1 + t - 1, i + 1};
        }
        else {
            return {1 + i, i + 1 - (t - (i + 1))};
        }
    }

}
int main() {
    int n;
    while (cin >> n and n) {
        point pos = position(n);
        printf("%d %d\n", pos.x, pos.y);
    }
}
