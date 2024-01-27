#include <bits/stdc++.h>
using namespace std;
#define ll long long



int main() {
    int n, m; cin >> n >> m;
    int ar[n] = {};
    int v[n][m] = {};
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &v[i][j]);
        }
        ans ^= v[i][0];
    }
    if (ans) {
        printf("TAK\n");
        for (int i = 0; i < n; i++)printf("1 ");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] != v[i][0]) {
                printf("TAK\n");
                for (int x = 0; x < n; x++) {
                    if (x == i)printf("%d ", j + 1);
                    else printf("1 ");
                }
                return 0;
            }
        }
    }
    printf("NIE");
}