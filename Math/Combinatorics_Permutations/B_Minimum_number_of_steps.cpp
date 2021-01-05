#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string s; cin >> s;
    const int mod = 1e9 + 7;
    ll b = 0, ans = 0;
    for (int i = s.size() - 1; i >= 0;i--) {
        if (s[i] == 'b')b++;
        else {
            ans += b;
            if (ans > mod)ans %= mod;
            b *= 2;
            if (b > mod)b %= mod;
        }
    }
    cout << ans << endl;
}