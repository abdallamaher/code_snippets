#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int n; cin >> n;
    map< pair<int, int>, int >mp;
    vector< pair<int, int> > v;
    v.push_back({ 0, 0 });
    mp[{0, 0}] = 1;
    for (int i = 0; i < n;i++) {
        int a, b; cin >> a >> b;
        if (mp[{a, b}] == 1)continue;
        mp[{a, b}] = 1;
        v.push_back({ a, b });
    }
    set<int> st;
    int ans = 0;
    for (int i = 1; i < v.size(); i++) {
        int x = min(v[i].first, v[i].second) - max(v[i - 1].first, v[i - 1].second);
        if (x >= 0) {
            ans += x;
            if (st.count(max(v[i - 1].first, v[i - 1].second)) == 0)ans++;
            st.insert(min(v[i].first, v[i].second));
        }
    }
    cout << max(1, ans) << endl;
}