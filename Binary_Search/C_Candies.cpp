#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;

ll can(ll x) {
    ll sum = 0, cur = n;
    while (cur > 0) {
        ll m = min(cur, x);
        cur -= m;
        sum += m;
        cur -= cur / 10;
    }
    return sum * 2 >= n;
}

int main() {
    scanf("%lld", &n);
    ll st = 1, en = n, mid;
    while (st < en) {
        mid = (st + en) / 2;
        if (can(mid)) en = mid;
        else st = mid + 1;
    }
    printf("%lld\n", en);
}