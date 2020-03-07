#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int n, MX;
int ar[N];
ll s1, s2;
int main() {
    cin.sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        s1 += ar[i];
        MX = max(ar[i], MX);
    }
    ll st = 0, en = 1e12;
    while (st < en) {
        ll mid = (st + en) >> 1;
        if (mid * n - mid >= s1 && mid >= MX)
            en = mid ;
        else
            st = mid + 1;
    }
    printf("%lld", st);
    return 0;
}
 






