#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
struct p {
    long double x, y;
    friend p operator+(p a, p b) {
        return {a.x + b.x, a.y + b.y};
    }
};

int n;
string s;
deque<int> circles;
deque<int> squares;
p tri = {1/2.0, sqrt(3) / 2.0};
p cir = {1/2.0, 1/2.0};
p squ = {0, 1};
long double countour(char t) {
    switch (t) {
        case 'T': return 1.5;
        case 'S': return 2;
        case 'C': return M_PI / 2.0;
    }
}
long double dist(p a, p b) {
    return hypot(a.x - b.x, a.y - b.y);
}
long double get_dist(int i, int j) {
    ////printf("s %c%c\n", s[i], s[j]);
    ////printf("ij %d%d\n", i, j);
    if (s[i] == s[j]) return j - i;
    else {
        if (s[i] == 'T') {
            if (s[j] == 'C') {
                long double d = dist(tri + p{i, 0}, cir + p{j, 0});
                long double b = j - i;
                long double v = sqrt(d*d - 1 / 4.0);
                return v + (M_PI / 2.0 - acos(b / d) - asin(v / d))/2.0;
            }
            else {
                return dist(tri + p{i, 0}, squ + p{j, 0}) + 1/2.0;
            }
        }
        if (s[i] == 'S') {
            if (s[j] == 'C') {
                return j - i;
            }
            else {
                return 1 / 2.0 + dist(squ + p{i + 1, 0}, tri + p{j, 0});
            }
        }
        if (s[i] == 'C') {
            if (s[j] == 'S') {
                return j - i;
            }
            else {
                long double d = dist(tri + p{j, 0}, cir + p{i, 0});
                long double b = j - i;
                long double v = sqrt(d*d - 1 / 4.0);
                //printf("d = %llf b = %llf v = %llf\n", d, b, v);
                //printf("alpha = %llf beta = %llf\n", acos(b/d), asin(v/d));
                return v + (M_PI / 2.0 - acos(b / d) - asin(v / d)) / 2.0;
            }
        }
    }
}
int next_circle() {
    if (circles.size() == 0) return -1;
    return circles.front();
}
int next_square() {
    if (squares.size() == 0) return -1;
    return squares.front();
}

int main() {
    while (cin >> n) {
        cin >> s;
        circles.clear();
        squares.clear();
        int i = 0;
        for (auto& c : s) {
            switch (c) {
                case 'T':
                break;
                case 'S':
                squares.push_back(i);
                break;
                case 'C':
                circles.push_back(i); 
                break;
            }
            i++;
        }
        long double ans = 0;
        ans += countour(s[0]);
        for (i = 0; i < s.size();) {
            int nc = next_circle();
            int ns = next_square();
            ////printf("what %d%d\n", nc, ns);
            if (nc == -1 && ns == -1) {
                long double d = get_dist(i, s.size() - 1);
                // cout << 'd' << d << ' ';
                ans += d;
                i = s.size();
            }
            else if (nc == -1) {
                squares.pop_front();
                ans += get_dist(i, ns);
                i = ns;
            }
            else if (ns == -1) {
                circles.pop_front();
                ans += get_dist(i, nc);
                i = nc;
            }
            else if (ns < nc) {
                squares.pop_front();
                ans += get_dist(i, ns);
                i = ns;
            }
            else if (nc < ns) {
                circles.pop_front();
                ans += get_dist(i, nc);
                i = nc;
            }
            //printf("ans %llf\n", ans);
        }
        ans += countour(s[s.size() - 1]);
        ans += (s.size() - 1);
        printf("%.9llf\n", ans);
    }
}