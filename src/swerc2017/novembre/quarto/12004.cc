#include <iostream>
#include <algorithm>
using namespace std;
int findSwaps( int n, int a[] )
{
int count = 0, i, j, temp, b[100000];
for( i = 0; i < n; i++ ) {
b[i] = a[i];
}
for( i = 0; i < n; i++ ) {
for( j = 0; j < n - 1; j++ ) {
if( b[j] > b[j+1] ) {
temp = b[j];
b[j] = b[j+1];
b[j+1] = temp;
count++;
}
}
}
return count;
}
int fact(int n) {
    if (n <= 1) return 1;
    return n *fact(n-1);
}
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
int a[100];
int n = 3;
int main() {
    for (n = 1; n < 8; n++) {
        for (int i = 0; i < n; i++) {
            a[i] = i;
        }
        long long ans = 0;
        do {
            ans += findSwaps(n, a);
        } while (next_permutation(a, a + n));
        int g = gcd(ans, fact(n));
        cout << ans/g << '/' << fact(n)/g << endl;

    }
}