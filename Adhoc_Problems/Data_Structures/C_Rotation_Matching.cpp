#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int n; cin >> n;
    vector<int> a(n + n), b(n + n), pos(n + n), shift(n + n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);

        int s = pos[b[i]] - i;
        if (s < 0)s += n;

        shift[s]++;
        mx = max(mx, shift[s]);
    }

    printf("%d\n", mx);

}