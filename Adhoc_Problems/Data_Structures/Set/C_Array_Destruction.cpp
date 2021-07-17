#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<int> v;

inline bool check(int x) {
    int t = x;
    multiset<int> st;
    for (int i = 0; i < n; i++)st.insert(v[i]);

    vector<pair<int, int>> ans;
    while (st.size()) {
        auto a = *st.rbegin();
        int b = x - a;
        st.erase(st.find(a));
        if (st.count(b) == 0) return 0;
        st.erase(st.find(b));
        ans.push_back({ a, b });
        x = max(b, a);
    }
    printf("YES\n%d\n", t);
    for (auto it : ans) {
        printf("%d %d\n", it.first, it.second);
    }
    return 1;
}

inline void solve() {
    cin >> n; n <<= 1;
    v.resize(n);
    for (int i = 0;i < n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (check(v[i] + v[0]))return;
    }
    puts("NO");
    return;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}