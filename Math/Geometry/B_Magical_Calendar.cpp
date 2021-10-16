#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    ll n, weekDays; cin >> n >> weekDays;
    if (n > weekDays) {
        // n=17  weekDays=3
        cout << weekDays * (weekDays + 1) / 2 << endl;
    }
    else {
        // n=3  weekDays=17
        n--;
        cout << n * (n + 1) / 2 + 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}