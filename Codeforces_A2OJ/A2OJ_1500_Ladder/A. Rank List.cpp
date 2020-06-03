#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int ,int>
int n, k;
pii  ar[55];
map<pii, int> mp;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        ar[i] = { x, y };
        mp[{x, y}]++;
    }
    
    sort(ar, ar + n, [](pii& x, pii& y) {
        if (x.first > y.first)
            return 0;
        if (x.first == y.first && x.second <= y.second)
            return 0;
        return 1;
        });

    cout << mp[ar[n - k]] << endl;
    return 0;
}