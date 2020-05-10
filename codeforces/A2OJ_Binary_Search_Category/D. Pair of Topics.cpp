#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define ll long long
const int N = 2e5 + 7;

int n;
int t[N], s[N], ans[N];
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        ans[i] = t[i] - s[i];
    }
    ll cnt = 0;
    sort(ans, ans + n);
    // -1 -2 0 3 3 5
    for (int i = 0; i < n - 1; i++) {
        if (ans[i] <= 0) {
            int p = upper_bound(ans, ans + n, abs(ans[i])) - ans;
            cnt = cnt + n - p;
        }
        else
            cnt = cnt + n - i - 1;
    }
    cout << cnt;
    return 0;
}