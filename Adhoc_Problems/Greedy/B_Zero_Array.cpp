#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n; cin >> n;
    ll sum = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        sum += x;
        if (x > mx)mx = x;
    }
    if (sum & 1 ^ 1 && sum - mx >= mx)puts("YES");
    else puts("NO");
}