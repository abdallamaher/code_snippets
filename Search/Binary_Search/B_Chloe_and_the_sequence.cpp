#include <bits/stdc++.h>
using namespace std;
#define ll long long 


int main() {
    ll n, k;scanf("%lld%lld", &n, &k);
    ll st = 1, en = (1ll << n) - 1, mid;
    while (1) {
        mid = (st + en) / 2;
        if (mid == k) {
            cout << n << endl;
            break;
        }
        else if (mid > k) {
            en = mid - 1;
        }
        else st = mid + 1;

        n--;
    }

    return 0;
    while (1) {
        if (k == (1ll << (n - 1))) {
            cout << n << endl;
            break;
        }

        if (k > (1ll << (n - 1))) {
            k = k - (1ll << (n - 1));
        }

        n--;
    }
    return 0;
}