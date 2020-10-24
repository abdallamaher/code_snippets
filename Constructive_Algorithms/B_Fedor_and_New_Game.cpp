#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int check(int x) {
    int res = 0;
    for (int i = 0; i <= 30; i++) {
        if ((x >> i) & 1)res++;
    }
    return res;
}

int main() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> v(m + 5);
    for (int i = 0; i <= m; i++) {
        cin >> v[i];
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (check(v[m] ^ v[i]) <= k) ++ans;
    }
    cout << ans << '\n';
    return 0;
}