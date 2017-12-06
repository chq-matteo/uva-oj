#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
double PI = 3.14159265358979323846;
using namespace std;
double EPS = 0.000000001;
struct vec { double x, y; };
struct point {
    double x;
    double y;
    friend bool operator==(point a, point b) {
        return a.x == b.x and b.y == a.y;
    }
};
double dist(point p1, point p2) {
return hypot(p1.x - p2.x, p1.y - p2.y); }
double cross(vec a, vec b){return a.x * b.y - a.y * b.x; }
vec toVec(point a, point b) { // vector a->b
return {b.x - a.x, b.y - a.y}; }
vec scale(vec v, double s) { // nonnegative s 
    return
{v.x * s, v.y * s}; }
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0; }
point translate(point p, vec v) {//translate p by v
return {p.x + v.x , p.y + v.y}; }
double dot(vec a, vec b) {
return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v) {
return v.x * v.x + v.y * v.y; }
double angle(point a, point o, point b) {
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) *
    norm_sq(ob))); }
bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; }
vector<point> kingdom[101];
point pivot;
bool angleCmp(point a, point b) { // angle-sorting function
    if (collinear(pivot, a, b)) // special case
    return dist(pivot, a) < dist(pivot, b);
    // check which one is closer
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; }
vector<point> CH(vector<point> P) {
    // the content of P may be reshuffled
    int i, j, n = (int)P.size();
    if (n <= 3) {
    if (!(P[0] == P[n-1])) P.push_back(P[0]);
    // safeguard from corner case
    return P; // special case, the CH is P itself
    }//find P0=point with lowest Y and if tie:rightmost X
    int P0 = 0;
    for (i = 1; i < n; i++)
    if (P[i].y < P[P0].y || (P[i].y == P[P0].y &&
    P[i].x > P[P0].x))
    P0 = i;
    point temp = P[0]; P[0] = P[P0]; P[P0] = temp;
    // swap P[P0] with P[0]
    // second, sort points by angle w.r.t. pivot P0
    pivot = P[0];// use global variable as reference
    sort(++P.begin(), P.end(), angleCmp);//skip P[0]
    // third, the ccw tests
    vector<point> S;
    S.push_back(P[n-1]);S.push_back(P[0]);
    S.push_back(P[1]);
    i = 2; // then, we check the rest
    while (i < n) { // note: N must be >= 3
    j = (int)S.size()-1;
    if (ccw(S[j-1], S[j], P[i]))
    S.push_back(P[i++]); // left turn, accept
    else S.pop_back(); }
    // or pop the top of S until we have a left turn
    return S; 
}

double A(vector<point> P) {
    double a = 0;
    for (int i = 1; i < P.size(); i++) {
        a += ((((P[i-1].x) / 2.0 ) * P[i].y) - (((P[i].x / 2.0)) * P[i-1].y));
    }
    // // cout << a;
    return a;
}
set<int> can;
bool inPolygon(point pt, const vector<point> &P) {
    if ((int)P.size() == 0) return false;
    double sum = 0; // assume first vertex = last vertex
    for (int i = 0; i < (int)P.size()-1; i++) {
    if (ccw(pt, P[i], P[i+1]))
    sum += angle(P[i], pt, P[i+1]);// ccw
    else sum -= angle(P[i], pt, P[i+1]); } //cw
    return fabs(fabs(sum) - 2*PI) < EPS; }
int main() {
    int n, x, y, k;
    k = -1;
    while (cin >> n and n != -1) {
        cin >> x >> y;
        
        k++;
        kingdom[k].push_back({x, y});
        for (int i = 0; i < n - 1; i++) {
            cin >> x >> y;
            kingdom[k].push_back({x, y});
        }
        kingdom[k] = CH(kingdom[k]);
        for (auto& p : kingdom[k]) {
            // cout << p.x << ' ' << p.y << endl;;
        }
        // cout << A(kingdom[k]) << endl;
        can.insert(k);
    }
    while (cin >> x) {
        cin >> y;
        vector<int> torem;
        // // cout << x << ' ' << y << endl;
        
        for (auto& q : can) {
            if (inPolygon({x, y}, kingdom[q])) {
                // // cout << x << ' ' << y << ' ' << q << endl;
                torem.push_back(q);
            }
        }
        for (auto& q : torem) {
            auto g = can.find(q);
            if (g != can.end()) {
                // // cout << 'h' << q;
                can.erase(g);
            }
        }
    }
    // // cout << "hi";
    double ans = 0;
    for (int i = 0; i <= k; i++) {

        auto g = can.find(i);
        // // cout << i << "khksf";
        if (g != can.end()) {
        }
        else {

            ans += abs(A(kingdom[i]));
        }
    }
    printf("%.2lf\n", ans);
}