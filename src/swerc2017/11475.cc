#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
char s[100001];
set<int> p['z' + 1];
bool is(int a, int b) {
    while (a <= b) {
        if (p[a] != p[b]) return false;
        a++;
        b--;
    }
    return false;
}
int max_pali_suffix(int a, int b) {
    return max_pali_suffix(p[s[]])
}
int main() {
    int n;
    while (scanf("%s\n", s)) {
        n = strlen(s);
        for (int i = 'a'; i <= 'z'; i++) {
            p[i].clear();
        }
        for (int i = 'A'; i <= 'Z'; i++) {
            p[i].clear();
        }
        for (int i = 0; i < n; i++) {
            p[i].insert(i);
        }
        int ans = 1;
        
        // for (int i = n-1; i >= 0; i--) {
        // puo essere palindromo
        // s[i - k, i + k - 1] con k = n - i
        // ricerca binaria NO
        // s[i] puo trovarsi in p[s[i]] posizioni
        // }
    }

}