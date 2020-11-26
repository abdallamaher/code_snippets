#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n; string s; cin >> n >> s;
    if (n > 26)cout << -1;
    else {
        int ar[30] = { 0 };
        int ans = 0;
        for (auto c : s) {
            ar[c - 'a']++;
            if (ar[c - 'a'] > 1)ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}