#include <bits/stdc++.h>
using namespace std;
#define ll long long 

inline void solve() {
    int n; cin >> n;
    ll sum = 0;
    for (int i = 0; i < 3; i++) {
        ll tmp = 0;
        for (int a = 0; a < n - i; a++) {
            int x; scanf("%d", &x);
            tmp += x;
        }
        if (i)printf("%lld\n", sum - tmp);
        sum = tmp;
    }
}


int main() {
    int n; cin >> n;
    vector<int> a(n), b(n - 1), c(n - 2);
    for (auto &it : a)scanf("%d", &it);
    for (auto &it : b)scanf("%d", &it);
    for (auto &it : c)scanf("%d", &it);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    for (int i = 0; i < n; i++) {
        if (i == n - 1 || a[i] != b[i]) {
            printf("%d\n", a[i]);
            break;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (i == n - 2 || b[i] != c[i]) {
            printf("%d\n", b[i]);
            break;
        }
    }
}