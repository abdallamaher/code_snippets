#include <bits/stdc++.h>
using namespace std;
#define ll long long


inline void solve() {
    int n, k; cin >> n >> k;
    vector<int> ar(n + 5);
    for (int i = 0; i < n;i++) {
        scanf("%d", &ar[i]);
    }
    vector<int> cnt(2 * k + 1), pref(2 * k + 1);
    // num of pair no need to change to get sum
    for (int i = 0; i < n / 2; i++) {
        cnt[ar[i] + ar[n - i - 1]]++;
    }

    for (int i = 0; i < n / 2; i++) {
        // min and max each can get
        int l1 = 1 + ar[i], l2 = k + ar[i];
        int r1 = 1 + ar[n - i - 1], r2 = k + ar[n - i - 1];

        pref[min(l1, r1)]++;
        pref[max(l2, r2) + 1]--;
    }
    // num of pair change one element to get sum
    for (int sum = 2; sum <= 2 * k + 1; sum++) {
        pref[sum] += pref[sum - 1];
    }


    int ans = 1e9;
    for (int sum = 2; sum <= 2 * k; sum++) {
        ans = min(ans,
            // need to change one  + pair need to change 2
            (pref[sum] - cnt[sum]) + 2 * (n / 2 - pref[sum])
        );
    }

    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}