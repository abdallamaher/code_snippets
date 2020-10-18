#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> ar(26);
    for (int i = 0; i < m; i++) {
        char c; cin >> c;
        ar[c-'a']++;
    }
    ll sum = 0;
    for (int i = 0, cnt = 0;i < n; i++) {
        if (ar[s[i]-'a'])cnt++;
        if (!ar[s[i]-'a'] || i == n - 1) {
            sum += 1ll * cnt * (cnt + 1) / 2;
            cnt = 0;
        }
    }
    cout << sum << '\n';
    return 0;
}