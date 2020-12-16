#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define ll long long
#define ld long double

inline int sum(ll n) {
    int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

unordered_map<int, ll> ans;
void solve2(int i = 0, ll n = 0, ll msk = 0) {
    if (i == 11)return;
    int se = sum(n);
    if (ans[se] == 0)ans[se] = 1e18;
    ans[se] = min(ans[se], n);
    for (int j = 1; j < 10; j++) {
        if (!(msk & (1 << j))) {
            solve2(i + 1, n * 10 + j, msk | (1 << j));
        }
    }
    return;
}

inline void go() {
    for (int i = 1; i < 10;i++) {
        for (int a = 1; a < 10; a++) {
            ll n = i;
            ans[n] = n;
            for (int j = a; j < 10; j++) {
                if (i == j)continue;
                n = n * 10 + j;
                int su = sum(n);
                if (ans[su] == 0)ans[su] = 1e18;
                ans[su] = min(ans[su], n);
            }
        }
    }
}

int main() {
    go();
    int t; scanf("%d", &t);
    while (t--) {
        int x; cin >> x;
        if (ans[x])cout << ans[x] << endl;
        else cout << -1 << endl;
    }
}