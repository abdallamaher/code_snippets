#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 5;
int ar[N], first[N];

int main() {
    int n, q; cin >> n >> q;
    for (int i = 1;i <= n; i++) {
        scanf("%d", &ar[i]);
    }
    for (int i = n; i > 0; i--) {
        if (ar[i] != ar[i + 1]) {
            first[i] = i;
        }
        else {
            first[i] = first[i + 1];
        }
    }
    
    while (q--) {
        int l, r, x, ans; scanf("%d%d%d", &l, &r, &x);
        if (ar[l] == x) {
            if (first[l] >= r) {
                ans = -1;
            }
            else {
                ans = first[l] + 1;
            }
        }
        else {
            ans = l;
        }
        printf("%d\n", ans);
    }
}