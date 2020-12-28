#include <bits/stdc++.h>
using namespace std;
#define ll long long


int solve() {
    int n; cin >> n;
    int ar[n + n] = {};
    for (int i = 0;i < n; i++) {
        scanf("%d", ar + i);
    }
    vector<pair<int, int>> data;
    for (int i = 0; i < n;i++) {
        int j = i;
        while (ar[i] == ar[j])j++;
        int len = j - i;
        i = j - 1;
        data.push_back({ ar[i], len });
    }
    int ans = data[0].second, cnt = data[0].second,
        mx = data[0].first, mn = data[0].first;
    for (int i = 1; i < data.size();i++) {
        int a = max(data[i].first, mx);
        int b = min(data[i].first, mn);
        if (a - b < 2)cnt += data[i].second, mx = a, mn = b;
        else {
            cnt = data[i].second;
            mx = data[i].first, mn = data[i].first;
            if (abs(data[i].first - data[i - 1].first) < 2) {
                cnt += data[i - 1].second;
                mx = max(mx, data[i - 1].first);
                mn = min(mn, data[i - 1].first);
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}

int main() {
    int n; cin >> n;
    int ar[n + n] = {};
    for (int i = 0;i < n; i++) {
        scanf("%d", ar + i);
    }
    multiset<int> st;
    int j = 0, ans = 0;
    for (int i = 0; i < n;i++) {
        while (st.size() && (abs(ar[i] - *st.begin()) > 1 || abs(ar[i] - *st.rbegin()) > 1)) {
            st.erase(st.find(ar[j]));
            j++;
        }
        st.insert(ar[i]);
        ans = max(ans, (int)st.size());
    }
    cout << ans << endl;
}