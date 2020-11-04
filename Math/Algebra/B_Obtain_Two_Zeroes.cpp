#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; scanf("%d %d", &n, &m);
        if (n < m)swap(n, m);
        if (m * 2 < n)puts("no");
        else if((m + n) % 3)puts("no");
        else puts("yes");
    }
    return 0;
}