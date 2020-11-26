#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n, l; cin >> n >> l;
    int ans = 0;
    string a, b;
    map<string, int> mp;
    while (n--) {
        string s;cin >> s;
        string rs = s;
        reverse(rs.begin(), rs.end());
        if (mp[rs]) {
            ans += 2 * l;
            a += s;
            b = rs + b;
            mp[rs]--;
        }
        else mp[s]++;
    }

    for (auto it : mp) {
        string x = it.first;
        reverse(x.begin(), x.end());

        if (it.second && x == it.first) {
            b += x;
            ans += l;
            break;
        }
    }

    cout << ans << endl;
    cout << b + a;
    return 0;
}