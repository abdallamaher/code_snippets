#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


int main() {
    int n, m; cin >> n >> m;
    vector<int> cand(n);
    for (int j = 0; j < m; j++) {
        vector<int> v(n);
        for (int i = 0;i < n; i++) {
            int x; scanf("%d", &x);
            v[i] = x;
        }
        int x = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] > v[x])x = i;
        }
        cand[x]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        // cout << cand[i] << '\n';
        if (cand[i] > cand[ans])ans = i;
    }
    cout << ans + 1 << '\n';
    return 0;
}