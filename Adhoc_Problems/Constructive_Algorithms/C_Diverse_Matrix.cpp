#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

const int N = 505;
int r[N], c[N];

int main() {
    int n, m; scanf("%d %d", &n, &m);
    if (n == 1 && m == 1)return cout << 0, 0;
    int sw = 0;
    if (n > m)swap(n, m), sw = 1;
    for (int i = 1; i <= n; i++) r[i] = i;
    for (int i = 1; i <= m; i++) c[i] = n + i;
    if (sw) {
        swap(r, c);
        swap(n, m);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d%c", r[i] * c[j], " \n"[j == m]);
        }
    }
}