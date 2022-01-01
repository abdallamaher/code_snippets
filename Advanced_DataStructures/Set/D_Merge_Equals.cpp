#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 5;
ll ar[N];
map<ll, set<int> > mp;
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%lld", ar + i);
        mp[ar[i]].insert(i);
    }
    set<pair<int, ll>> ans;
    for (auto& it : mp) {
        set<int>& s = it.second;
        while (s.size() > 1) {
            s.erase(s.begin());
            mp[it.first * 2].insert(*s.begin());
            s.erase(s.begin());
        }
        if (s.size())ans.insert({ *s.begin(), it.first });
    }

    printf("%d\n", ans.size());
    for (auto it : ans) {
        printf("%lld ", it.second);
    }
}