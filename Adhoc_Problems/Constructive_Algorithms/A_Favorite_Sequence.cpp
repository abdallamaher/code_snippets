#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

inline void solve() {
    int n; cin >> n;
    vector<int> v(n + n);
    for (int i = 0; i < n; i++)scanf("%d", &v[i]);
    int i = 0, j = n - 1;
    for (; i < j; i++, j--) {
        printf("%d %d ", v[i], v[j]);
    }
    if (n & 1)printf("%d", v[i]);
    puts("");
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}