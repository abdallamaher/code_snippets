#include <bits/stdc++.h>
using namespace std;
#define ll long long


inline void solve() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 1e9;
    for (int i = 0; i < 26; i++) {

        string t;
        for (int j = 0; j < n; j++) {
            if (s[j] != char(i + 'a'))t += s[j];
        }

        string tt = t;
        reverse(tt.begin(), tt.end());

        if (t == tt) {
            int tmp = 0;
            for (int j = 0, g = n - 1; j < g;) {
                if (s[j] == s[g]) {
                    g--, j++;
                    continue;
                }
                if (s[j] == char(i + 'a'))j++;
                else g--;
                tmp++;
            }
            ans = min(ans, tmp);
        }

    }
    if (ans == 1e9) ans = -1;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}