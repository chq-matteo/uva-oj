// 443 Humble Numbers
// it's 11th, 12th, 13th not 11st, 12nd, 13rd
#include <iostream>
#include <set>
using namespace std;
long long ans[10000];
char pre[10][3] = {
    "th",
    "st",
    "nd",
    "rd",
    "th",
    "th",
    "th",
    "th",
    "th",
    "th"
};
int main() {
    int n;
    long long p[4] = {1, 1, 1, 1};
    long long v[4] = {2, 3, 5, 7};
    ans[1] = 1;
    for (int i = 2; i <= 5842; i++) {
        long long c = 2000000000000000ll;
        int k = 0;
        for (int j = 0; j < 4; j++) {
            if (ans[p[j]] * v[j] < c) {
                k = j;
                c = ans[p[j]] * v[j];
            }
        }
        ans[i] = c;
        
        // printf("%d %d %d %d\n", p[0], p[1], p[2], p[3]);
    }
    while (cin >> n and n) {
        printf("The %d%s humble number is %lld.\n", n, (n%100 / 10 != 1 ? pre[n%10] : "th"), ans[n]);
    }
}