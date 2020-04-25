#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e2 + 7;

int n, cnt;
char g[N][N];
int r[N], c[N], mark[N];

int main() {
    cin.sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
            if (g[i][j] == '.') {
                r[i] = r[i - 1] + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[j][i] == '.') {
                c[i] = c[i - 1] + 1;
            }
        }
    }
    //printf("%d %d\n", r[n], c[n]);
    if (r[n] < n && c[n] < n)return cout << -1, 0;
    for (int i = 1; r[n] == n && i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[i][j] == '.') {
                printf("%d %d\n", i, j);
                break;
            }
        }
    }
    if (r[n] == n)return 0;
    for (int i = 1; c[n] == n && i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[j][i] == '.') {
                printf("%d %d\n", j, i);
                break;
            }
        }
    }
    return 0;
}