#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n, cap; cin >> n >> cap;
    ll sum = 0, mxP = 0, mxN = 0;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        sum += x;
        if (sum > 0)mxP = max(mxP, sum);
        else if (sum < 0)mxN = max(mxN, -1 * sum);
    }
    cout << max(0ll, cap + 1 - mxP - mxN);
}