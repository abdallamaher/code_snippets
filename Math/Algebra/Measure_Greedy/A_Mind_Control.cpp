#include <bits/stdc++.h>
using namespace std;
#define ll long long
int ar[5555];

inline void solve() {
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)scanf("%d", ar + i);
    m--;
    k = min(k, m);
    int dont_controll = m - k;

    int ans = -2e9;
    for (int left_cntrl = 0; left_cntrl <= k; left_cntrl++) {
        int tmp = 2e9;
        for (int left_not_cntrl = 0;left_not_cntrl <= dont_controll; left_not_cntrl++) {
            int left = left_cntrl + left_not_cntrl;
            int right = (k - left_cntrl) + (dont_controll - left_not_cntrl);
            tmp = min(tmp, max(ar[left], ar[n - right - 1]));
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}


int main() {
    int t; cin >> t;
    while (t--)solve();
}