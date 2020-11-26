#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    ll n, k; cin >> n >> k;
    n %= 6;

    int ar[4] = {};
    ar[k] = 1;
    for (int i = n; i > 0; i--) {
        if (i & 1)swap(ar[0], ar[1]);
        else swap(ar[1], ar[2]);
    }
    cout << find(ar, ar + 4, 1) - ar << endl;
    return 0;
}