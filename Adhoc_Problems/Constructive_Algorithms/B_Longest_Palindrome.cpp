#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n, m; cin >> n >> m;
    map<string, int> mp;
    string a, b;
    while (n--) {
        string s; cin >> s;
        string st = s;
        reverse(st.begin(), st.end());
        if (mp[s]) {
            a += s;
            b += s;
            mp[s]--;
        }
        else if (mp[st]) {
            a += st;
            b += st;
            mp[st]--;
        }
        else mp[s]++;
    }
    string c;
    for (auto& it : mp) {
        string st = it.first;
        reverse(st.begin(), st.end());
        if (st == it.first && c.size() < st.size())c = st;
    }
    reverse(b.begin(), b.end());
    string ans = a + c + b;
    cout << ans.size() << '\n' << ans << '\n';
    return 0;
}