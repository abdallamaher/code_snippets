#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    string s; cin >> s;
    int n = s.size();
    for (auto& it : s)it -= '0';


    int p = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] + s[i + 1] >= 10) {
            p = i;
        }
    }

    int num = s[p] + s[p + 1];

    s[p + 1] = num % 10;
    num /= 10;
    if (num)s[p] = num;
    else s[p] = -1;

    for (auto& it : s) if (it >= 0)cout << char(it + '0');
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}