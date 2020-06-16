#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int q, n, k;
pair<int, pair<int, int>> v[110];

bool check(int l1, int h1, int l2, int h2) {
    if (l1 >= l2&& l1 <= h2)return 1;
    if (h1 >= l2 && h1 <= h2)return 1;
    if (l2 >= l1 && h2 <= h1)return 1;
    if (l2 <= l1 && h2 >= h1)return 1;
    return 0;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> q;
    while (q--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            int t, l, h; cin >> t >> l >> h;
            v[i] = { t, {l, h} };
        }
        v[0] = { 0, {k, k} };
        sort(v, v + n+1);
        int f = 0;
        for (int i = 1; i <= n; i++) {
            int t = v[i].first - v[i - 1].first;

            int& l1 = v[i - 1].second.first;
            int& h1 = v[i - 1].second.second;
            h1 += t;
            l1 -= t;

            int& l2 = v[i].second.first;
            int& h2 = v[i].second.second;


            if (check(l1, h1, l2, h2)) {
                if(l1 > l2)l2 = l1;
                if(h1 < h2)h2 = h1;
            }
            else
                f = 1;
        }
        if (f)
            cout << "NO\n";
        else 
            cout << "YES\n";
    }
    return 0;
}

