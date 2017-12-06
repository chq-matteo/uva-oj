// 12696 Cabin Baggage Uva
#include <iostream>
using namespace std;
int main() {
    int a, b, c, w;
    int da, db, dc, dw;
    int ma = 6000, mb = 4500, mc = 2500, mw = 700, ms = 12500;
    // there could be rounding error, but unlikely
    int t, ans = 0;
    cin >> t;
    while(t--) {
        scanf("%d.%d %d.%d %d.%d %d.%d\n", &a, &da, &b, &db, &c, &dc, &w, &dw);
        a *= 100;
        b *= 100;
        c *= 100;
        w *= 100;
        if (((a+da <= ma and b+db <= mb) and c+dc <= mc or a+da + b+db + c+dc <= ms) and w+dw <= mw) {
            cout << "1\n";
            ans++;
        }
        else {
            cout << "0\n";
        }
    }
    cout << ans << '\n';
}