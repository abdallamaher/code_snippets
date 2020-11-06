#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int n; cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    int x = sqrt(1.0 * g[1][0] * g[2][0] / g[2][1]);
    printf("%d ", x);
    for (int i = 1; i < n; i++)printf("%d ", g[i][0] / x);
    return 0;
}