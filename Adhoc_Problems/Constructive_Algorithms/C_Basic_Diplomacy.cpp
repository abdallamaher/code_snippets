#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, m; scanf("%d %d", &n, &m);
    vector<int> days[m + m] = {};
    for (int i = 0; i < m; i++) {
        int x; scanf("%d", &x);
        for (int ui = 0; ui < x; ui++) {
            int y; scanf("%d", &y);
            if (days[i].empty())days[i].push_back(i);
            days[i].push_back(y);
        }
    }
    sort(days, days + m, [](vector<int>& f, vector<int>& s) {
        return f.size() < s.size();
        });
    int ok = 1;
    map<int, int> mp;
    vector<pair<int, int>> v;
    for (int i = 0; i < m; i++) {
        set< pair<int, int> > st;
        for (int ii = 1; ii < days[i].size(); ii++) {
            int y = days[i][ii];
            st.insert({ mp[y], y });
        }
        int x = (*st.begin()).second;
        v.push_back({ days[i][0], x });
        mp[x]++;
        if (mp[x] > (m + 1) / 2)ok = 0;
    }
    sort(v.begin(), v.end());
    if (ok) {
        puts("YES");
        for (int i = 0; i < m; i++)printf("%d%c", v[i].second, " \n"[i == m - 1]);

    }
    else {
        puts("NO");
    }
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}