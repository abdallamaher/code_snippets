#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, k; string s;
    cin >> n >> k >> s;
    // all i , i +k , i + 2k .. should be the same
    for (int i = 0; i < k; i++) {
        int cnt = 0, ones = 0, zeros = 0;
        for (int j = i; j < n; j += k) {
            if (s[j] != '?') {
                cnt++;
                ones += (s[j] - '0');
                zeros += 1 - (s[j] - '0');
            }
        }
        if (ones && cnt != ones) {
            cout << "NO\n";
            return;
        }
        if (cnt == 0)continue;
        if (cnt == ones)s[i] = '1';
        else s[i] = '0';
    }

    // ones zeros count should be the same
    int ones = 0, zeros = 0;
    for (int i = 0; i < k; i++) {
        if (s[i] == '1')ones++;
        else if (s[i] == '0')zeros++;
    }
    int diff = abs(ones - zeros);
    int rem = k - ones - zeros;
    if (rem >= diff && (rem - diff) % 2 == 0)
        cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}
