#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
string s, ans;

bool check(string st) {
    for (int i = 0; i <= n - (int)st.size(); i++) {
        // int f = 1;
        // for (int j = 0; j < st.size(); j++) {
        //     f &= (s[i + j] == st[j]);
        // }
        // if (f)return 0;

        if (s.substr(i, st.size()) == st)
            return 0;
    }
    return 1;
}

void gen(string st) {

    if (st.size() && check(st)) {
        if (st.size() < ans.size())ans = st;
    }

    if (st.size() == 3)return;

    for (char c = 'a'; c <= 'z'; c++) {
        gen(st + c);
    }
}

inline void solve() {
    cin >> n >> s;
    ans = string(1005, 'z');
    gen("");
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}