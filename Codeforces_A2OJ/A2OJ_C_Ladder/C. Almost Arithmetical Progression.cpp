#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
int n;
vector<int> adj[N];
vector<int> v;
unordered_set<int> s;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        adj[x].push_back(i);
        s.insert(x);
    }
    for (auto it : s)v.push_back(it);
    int ans = 1, cnt = 0;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            ans = max(ans, (int)max(adj[v[i]].size(), adj[v[j]].size()));
            vector<int> v1, v2;
            if (adj[v[i]][0] < adj[v[j]][0]) {
                v1 = adj[v[i]];
                v2 = adj[v[j]];
            }
            else {
                v2 = adj[v[i]];
                v1 = adj[v[j]];
            }
            cnt = 0;
            for (int a = 0, p = 0; a < v1.size(); ++a) {
                if (a && v1[a] < v2[p - 1]) continue;
                int next = upper_bound(v2.begin() + p, v2.end(), v1[a]) - v2.begin();
                if (next < v2.size()) {
                    cnt += 2;
                    p = next + 1;
                }
                else {
                    cnt++;
                    break;
                }
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans;

    return 0;
}