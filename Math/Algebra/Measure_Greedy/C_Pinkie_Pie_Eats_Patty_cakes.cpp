#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    for (auto& it : v)scanf("%d", &it), mp[it]++;
    int mx = 0;
    for (auto& it : mp)mx = max(it.second, mx);
    int maxC = 0;
    for (auto& it : mp)maxC += (it.second == mx);
    int rest = n - mx * maxC;
    int fill = rest / (mx - 1);
    cout << fill + (maxC - 1) << endl;      // 1 2 3 ? 1 2 3 ? 1 2 3
}

const int N = 1e5 + 5;
int n;
int ar[N];

bool check(int x) {
    vector<int> freq(n + 1, 0);
    vector<int> can_eat[n + 1] = {};
    // cerr << x << endl;
    for (int i = 0; i < n; i++) {
        freq[ar[i]]++;
    }
    for (int i = 0;i <= n;i++) if (freq[i]) {
        can_eat[0].push_back(i);
    }
    priority_queue< pair<int, int> > pq;
    for (int i = 0; i < n;i++) {
        for (auto& it : can_eat[i]) pq.push({ freq[it], it });

        if (pq.empty())return 0;

        auto u = pq.top();
        pq.pop();
        freq[u.second]--;
        if (i + x < n && freq[u.second]) {
            can_eat[i + x].push_back(u.second);
        }
    }
    return 1;
}

inline void go() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }
    int l = 1, r = n + 1, mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l - 1 << endl;
}

int main() {
    int t; cin >> t;
    while (t--)go();
}