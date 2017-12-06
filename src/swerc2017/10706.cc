#include <iostream>
using namespace std;
int size = 11;
int slogn[size];
int get(n) {

}
int main() {
    slogn[1] = 1;
    for (int i = 2; i < size; i++) {
        slogn[i] = slogn[i - 1] + 10**i +
    }
    int t, n;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cin >> n;
        cout << get(n) << '\n';
    }
}