#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n; cin >> n;
    vector<int> v(n);
    map<int, ll> mp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        mp[v[i] - i + 1] += v[i];
    }
    ll mx = 0;
    for (auto it : mp) {
        if (it.second > mx)mx = it.second;
    }
    cout << mx;
}