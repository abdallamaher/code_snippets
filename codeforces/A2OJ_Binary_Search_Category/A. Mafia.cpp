#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define ll long long

int n, mx;
ll sum;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x > mx)mx = x;
        sum += x;
    }
    ll st = mx, en = 1e14, mid;
    while (st < en) {
        mid = (st + en) >> 1;
        if (mid*n - mid >= sum)
            en = mid;
        else
            st = mid + 1;
    }
    cout << en;
    return 0;
}