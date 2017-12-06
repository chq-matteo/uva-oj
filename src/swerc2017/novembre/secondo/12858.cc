#include <iostream>
#include <set>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
set<int> c[10005];
// pair<int, int> ss[10005];
vector<int> ss[10005];
// map<int, set<int>> k; //?
set<int> k;
int main() {
    int i, s;
    while (cin >> i) {
        cin >> s;
        k.clear();
        int cc;
        
        for (int j = 0; j < i; j++) {
            cin >> cc;
            c[j].clear();
            c[j].insert(cc);
            k.insert(cc);
        }
        int a, b;
        for (int j = 0; j < s; j++) {
            cin >> a >> b;
            // no questi sono quelli banali perche lui piglia max
            a--;
            b--;
            ss[a].push_back(b);
            ss[b].push_back(a);
            // ss[j] = {a, b};
            // devo prendere il gcd tree
            // k.insert(gcd(c[a], c[b]));
            // printf("added %d\n", (gcd(c[a], c[b])));
        }
        // int changes = 0;
        // do {    
        //     changes = 0;
        //     for (int j = 0; j < s; j++) {
        //             
        //     }
        // } while (changes);
        for (int j = 0; j < i; j++) {

        }
        cout << k.size() << '\n';
    }
}