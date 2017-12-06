#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
long long m[51];
int main() {
    int N, M, k;
    while (cin >> N >> M and N+M) {
        for (int i = 0; i < 51; i++) {
            m[i] = 0;
        }
        for (int i = 0; i < N; i++) {
            cin >> k;
            m[k]++;
        }
        sort(m, m+51);
        long long ans1 = 0;
        long long ans2 = 0;
        long long ans3 = 0;
        long long ans4 = 0;
        for (int i = 0; i < 51; i++) {
            ans1 += m[i] * (m[i] - 1) * (m[i] - 2) / 6;
            ans3 += m[i] * (m[i] - 1) * (m[i] - 2) * (m[i] - 3) / 24;
            ans3 += m[i] * (m[i] - 1) * (m[i] - 2) * (N - m[i]) / 6;
        }
        for (int i = 0; i < 51; i++) {
            for (int j = i+1; j < 51; j++) {
                for (int k = j+1; k < 51; k++) {
                    ans2 += m[i] * m[j] * m[k];
                    ans4 += m[i] * (m[i] - 1) * m[j] * m[k] / 2;
                    ans4 += m[i] * (m[j] - 1) * m[j] * m[k] / 2;
                    ans4 += m[i] * (m[k] - 1) * m[j] * m[k] / 2;
                    for (int q = k+1; q < 51; q++) {
                        ans4 += m[i] * m[j] * m[k] * m[q];
                    }
                }
            }
        }
        cout << ans1 + ans2 << ' ' << ans3 + ans4 << '\n';
    }
}