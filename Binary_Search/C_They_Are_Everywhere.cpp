#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; string st;
    cin >> n >> st;
    set<char>S;
    for (auto c : st)S.insert(c);
    int ar[200] = {};
    int cnt = 0, j = 0, ans = 1e9;
    for (int i = 0; i < n;i++) {
        if (ar[st[i]] == 0)cnt++;
        ar[st[i]]++;
        if (cnt == S.size()) {
            while (ar[st[j]] > 1)ar[st[j++]]--;
            ans = min(ans, i - j + 1);
        }
    }
    printf("%d\n", ans);
}

inline void go() {
    int n; string st;
    cin >> n >> st;
    map<char, vector<int>> pos;
    for (int i = 0;i < n; i++) pos[st[i]].push_back(i);
    int ans = 1e9;
    for (int i = 0;i < n; i++) {
        int mx = i;
        for (auto& it : pos) {
            if (it.first == st[i])continue;
            auto tmp = upper_bound(it.second.begin(), it.second.end(), i) - it.second.begin();
            if (tmp < it.second.size()) {
                mx = max(mx, it.second[tmp]);
            }
            else {
                mx = -1;
                break;
            }
        }
        if (mx != -1) {
            ans = min(ans, mx - i + 1);
        }
    }
    printf("%d\n", ans);
    return;
}

int main() {
    go();
}