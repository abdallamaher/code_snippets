#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


int main() {
    int n, rem; cin >> n >> rem;
    int sum = 0;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
        sum += (v[i].first + 1) / 2;
    }
    if (rem - sum < 0)cout << -1;
    else {
        vector<int> ans(n + n);
        sort(v.rbegin(), v.rend());
        for (int i = 0; i < n;i++) {
            int x = (v[i].first + 1) / 2;
            ans[v[i].second] += x;
            v[i].first -= x;
            rem -= x;
        }
        for (int i = 0; rem > 0 && i < n;i++) {
            int x = min(v[i].first, rem);
            ans[v[i].second] += x;
            rem -= x;
        }
        for (int i = 0;i < n;i++) {
            cout << ans[i] << ' ';
        }
    }
}