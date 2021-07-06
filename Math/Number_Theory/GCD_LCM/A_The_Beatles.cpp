#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k, a, b;
ll mx = 0, mn = 2e18;

void  check(ll l) {
    l = abs(l);
    ll jump_cnt = (n * k) / __gcd(n * k, l);
    /*
    jump_cnt = lcm(n * k, l) / l;
             = (n *  k) / __gcd(n*k, l) * l / l
    */
    mx = max(jump_cnt, mx);
    mn = min(jump_cnt, mn);
}

int main() {
    cin >> n >> k >> a >> b;
    /*
    start at location/node s
    a is distance from          [ start location s ] to nearest restorant
    jump_city is jumping from   [ start location s ] to by l
    b is distance from          [ jump_city ]        to nearest restorant

    
    start location doesn't matter
    let it start city be 1
    n_restor = 3    k_res_dis = 5
    a=1       b=2
    (Ra)EEEREE(bER)EEEE


    what matter is jump_length l
    l = (n) * k + (c)

    find mx and mn jump_cnt
    */
    for (int i = 0; i < n; i++) {
        check(i * k + a + b);
        check(i * k + a - b);
        check(i * k - a + b);
        check(i * k - a - b);
    }
    cout << mn << ' ' << mx << endl;
}