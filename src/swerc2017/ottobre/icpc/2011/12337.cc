#include <iostream>
#include <cmath>
using namespace std;
string buffer;
char m[800][800];
int index[256];
int freq[3];
// could be wrong :P
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
int dir[4][2] = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}
};
bool test(int r, int c) {
   //  cout << r << ' ' << c << '\n';
    // r--;
    // c--;
    int ro = r;
    int co = c;
    int x = 0;
    int y = 0;
    int *d = dir[0];
    bool row = true;
    int steps = 0;
    int count = 0;
    for (int i = 0; i < ro*co; i++) {
        // cout << x << ' ' << y << ' ' << steps  << ' ' << r << 'x' << c  << ' ' << row  << '\n';
        m[x][y] = buffer[i];
        steps++;
        if (row and steps == r) {
            count++;
            d = dir[count%4];
            steps = 0;
            c--;
            row = !row;
            steps = 0;
        }
        else if (!row and steps == c) {
            count++;
            d = dir[count%4];
            steps = 0;
            r--;
            row = !row;
            steps = 0;
        }
        x += d[0];
        y += d[1];
        /*
        if (x == r) {
            t++;
            x -= d[0];
            y -= d[1];
            d = dir[1];
            x += d[0];
            y += d[1];
        }
        else if (y == c) {
            r--;
            x -= d[0];
            y -= d[1];
            d = dir[2];
            x += d[0];
            y += d[1];
        }
        else if (x == l) {
            c--;
            x -= d[0];
            y -= d[1];
            d = dir[3];
            x += d[0];
            y += d[1];
        }
        else if (y == t) {
            l++;
            y++;
            x -= d[0];
            y -= d[1];
            d = dir[0];
            x += d[0];
            y += d[1];
        }
        */
    }
    bool ans = true;
    for (int i = 0; i < ro; i++) {
        for (int j = 0; j < co; j++) {
            //if (m[i][j] != m[i][0]) return false;
            ans = ans && m[i][j] == m[i][0];
            // cout << m[i][j];
        }
        // cout << '\n';
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    // index['B'] = 0;
    // index['G'] = 1;
    // index['W'] = 2;
    getline(cin, buffer);
    for (int tc = 1; tc <= T; tc++) {
        getline(cin, buffer);
        int len = buffer.size();
        // freq[0] = 0;
        // freq[1] = 0;
        // freq[2] = 0;
        // for (auto& c : buffer) {
        //     freq[index[c]] += 1;
        // }
        // cout << buffer;
        // int g = freq[0];
        // for (auto& i : freq) {
        //     g = gcd(g, i);
        // }
        int ans = -1;
        for (int i = 2; i < len; i++) {
            if (len % i == 0 and i != len) {
                if (test(len / (i), i)) {
                    if (ans != -1) {
                        ans = min(ans, len / (i) + i);
                    }
                    else {
                        ans = len / (i) + i;
                    }
                }
            }
        }
        cout << "Case " << tc << ": " << ans << '\n';
    }
}