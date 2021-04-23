#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n, l, r, s;
    scanf("%d %d %d %d", &n, &l, &r, &s);


    int x = r - l + 1;
    int mxSum = (n + n - x + 1) * x / 2;
    int mnSum = x * (x + 1) / 2;
    if (s > mxSum || s < mnSum) {
        cout << -1 << endl;
        return;
    }


    int ar[n + 1] = {};
    int ss = 0;
    for (int i = l, now = 1; i <= r; i++, now++)
        ar[i] = now, ss += now;
    map<int, int> mp;
    for (int i = r, ed = n; i >= l; i--) {
        while (ss < s && ar[i] < ed) {
            ar[i]++, ss++;
        }
        ed--;
        mp[ar[i]] = 1;
    }

    for (int i = 1, j = 1;i <= n; i++) {
        if (ar[i])continue;
        while (mp[j])j++;
        ar[i] = j;
        mp[j] = 1;
    }

    for (int i = 1; i <= n; i++)printf("%d ", ar[i]);
    cout << '\n';
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}