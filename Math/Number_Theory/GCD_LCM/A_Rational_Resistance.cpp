#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll a, b; cin >> a >> b;
    ll ans = 0;
    /*
    8/3 become 2 + 2/3 become 2 + 1/(3/2)
    make (3/2)      become (1 + (1/2))
    make (1/2)      become 2


    199/200 become 1/(200/199)
    make (200/199)  become 1 + (1/199)
    make (1/199)    become 199
    */
    while (b) {
        ans += a / b;
        a = a % b;
        swap(a, b);
    }
    cout << ans;
}