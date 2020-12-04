#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
string s;
string ans;
int ansN = 0;

inline string go(char c, int cnt) {
    string t = "RBG";
    auto p = t.find(c);
    p++;
    if (ans.size() && t[p % 3] == ans.back())p++;
    string st = string(cnt, c);
    for (int j = (cnt & 1); j < cnt; j += 2) {
        st[j] = t[p % 3];
    }
    return st;
}

inline void solve() {
    cin >> n;
    cin >> s;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1])cnt++;
        else {
            ans += go(s[i - 1], cnt);
            ansN += cnt / 2;
            cnt = 1;
        }
    }
    ans += go(s[n - 1], cnt);
    ansN += cnt / 2;
    printf("%d\n%s\n", ansN, ans.c_str());
}


int main() {
    int n; string s;
    cin >> n >> s;
    string t = "RBG";
    int ans = 0;
    for (int i = 1;i < n; i++) {
        if (s[i] == s[i - 1]) {
            ans++;
            auto p = t.find(s[i]);
            p++;
            if (s[i + 1] == t[p % 3])p++;
            s[i] = t[p % 3];
        }
    }
    printf("%d\n%s\n", ans, s.c_str());
}