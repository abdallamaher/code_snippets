#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, k;
const int N = 2e5 + 5;
int ar[N];

inline int get(int lim) {
    int tot = 0;
    int l = 1, r = n;
    while (l <= r) {
        if (l != r && ar[l] + ar[r] <= lim) {
            l++, r--;
            tot++;
        }
        else {
            r--;
            tot++;
        }
    }
    return tot;
}

int main() {
    scanf("%d %d", &n, &k);
    int st = 1, en = 1e9, mid;
    for (int i = 1;i <= n; i++) {
        scanf("%d", ar + i);
        st = max(st, ar[i]);
    }
    while (st < en) {
        mid = (st + en) / 2;
        if (get(mid) <= k) en = mid;
        else st = mid + 1;
    }
    cout << en << endl;
}