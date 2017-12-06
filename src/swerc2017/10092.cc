#include <iostream>
#include <vector>
using namespace std;
vector<int> p[1001];
int main() {
    int nk, np, nc, c;
    while (cin >> nk) {
        cin >> np;
        for (int i = 0; i < np; i++) {
            cin >> nc;
            for (int j = 0; j < nc; j++) {
                cin >> c;
                p[j].push_back(c);
            }
        }
    }
}