#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)scanf("%d", &b[i]);
    map<pair<int, int>, int> mp;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0 && b[i] == 0) {
            ans++;
            continue;
        }
        else if (a[i] == 0 && b[i])continue;
        else if (b[i] == 0) {
            mp[{0, 0}]++;
            continue;
        }

        int A = abs(a[i]), B = abs(b[i]);
        int g = __gcd(A, B);
        if (1ll * a[i] * b[i] < 0) mp[{A / g, B / g}]++;
        else mp[{-A / g, B / g}]++;
    }
    int mx = 0;
    for (auto it : mp)mx = max(mx, it.second);
    cout << ans + mx << endl;
}