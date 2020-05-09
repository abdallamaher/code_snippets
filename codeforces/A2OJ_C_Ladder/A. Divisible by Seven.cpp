#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s = "1689";
string ss, ans;
int ar[11];
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> ss;
    for (auto c : ss) {
        ar[c - '0']++;
    }
    ar[1]--, ar[6]--, ar[8]--, ar[9]--;
    int mod = 0;
    for (int i = 1; i < 11; i++) {
        while (ar[i]) {
            mod = (mod*10 + i) % 7;
            ar[i]--;
            ans += i + '0';
        }
    }
    mod *= 10000; mod %= 7;
    int mod2 = 0, f = 0;
    do {
        mod2 = 0;
        for (auto c : s) {
            mod2 = (mod2 * 10 + (c-'0')) % 7;
        }
        if ((mod + mod2) % 7 == 0) {
            f = 1;
            ans += s;
            break;
        }
    } while (next_permutation(s.begin(), s.end()));
    while (ar[0]) {
        ans += '0';
        ar[0]--;
    }
    if (f) cout << ans;
    else cout << 0;
    return 0;
}