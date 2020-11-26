#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        for (int j = x; j <= n && !v[j]; j++)
            v[j] = x;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", v[i]);
    }
    return 0;
}