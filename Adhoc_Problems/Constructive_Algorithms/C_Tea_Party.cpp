#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


int main() {
    int n, rem; cin >> n >> rem;
    int sum = 0;
    int tmp = rem;
    vector<pair<int, int>> v(n), ans(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
        int x = (v[i].first + 1) / 2;
        rem -= x;
        sum += v[i].first - x;
    }
    if (rem < 0)cout << -1;
    else if (rem > sum)cout << -1;
    else {
        sort(v.rbegin(), v.rend());
        for (int i = 0; i < n;i++) {
            int x = (v[i].first + 1) / 2;
            ans[i].first += x;
            ans[i].second = v[i].second;
            v[i].first -= x;
            tmp -= x;
        }
        for (int i = 0; tmp > 0 && i < n;i++) {
            int x = min(v[i].first, tmp);
            ans[i].first += x;
            tmp -= x;
        }
        sort(ans.begin(), ans.end(), [](pair<int, int> f, pair<int, int> s) {
            return f.second < s.second;
            });
        for (int i = 0;i < n;i++) {
            cout << ans[i].first << ' ';
        }

    }
}