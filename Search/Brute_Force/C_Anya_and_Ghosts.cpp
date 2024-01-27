#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, t, r;
const int N = 400;
int gt[N];
int cnt[N];

int main() {
    cin >> n >> t >> r;
    for (int i = 0; i < n; i++)scanf("%d", gt + i);

    if (t < r) {    // greedy
        puts("-1");
        return 0;
    }

    int ans = 0;
    for (int i = 0;i < n; i++) {    // brute
        for (int j = gt[i] - 1; cnt[gt[i]] < r; j--) {
            ans++;
            for (int f = j + 1; f <= j + t; f++) if (f >= 0)cnt[f]++;
        }
    }
    printf("%d\n", ans);
    return 0;
}