#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, k; string s;
    cin >> n >> k >> s;

    sort(s.begin(), s.end());

    if (s[0] != s[k - 1]) {
        cout << s[k - 1] << endl;
        return;
    }

    cout << s[0];
    if (s[k] == s.back()) {
        for (int i = k; i < k + ceil(1.0 * (n - k) / k); i++)cout << s[i];
    }
    else {
        for (int i = k; i < n; i++)cout << s[i];
    }

    cout << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}