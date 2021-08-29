#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
int main() {
    cin >> n >> m;
    int mnRange = 1e9;
    for (int i = 0; i < m; i++) {
        int a, b;scanf("%d%d", &a, &b);
        mnRange = min(mnRange, b - a + 1);
    }
    cout << mnRange << endl;
    for (int i = 0;i < n; i++) {
        printf("%d ", i % mnRange);
    }
}