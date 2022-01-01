#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int n, k, q; cin >> n >> k >> q;
    int N = 2e5 + 5;
    int ar[N] = {};
    for (int i = 0; i < n; i++) {
        int a, b; scanf("%d %d", &a, &b);
        ar[a]++;
        ar[b + 1]--;
    }
    int k_num[N] = {};
    for (int i = 1; i <= N; i++) {
        ar[i] += ar[i - 1];
        k_num[i] = k_num[i - 1];
        if (ar[i] >= k) {
            k_num[i]++;
        }
    }
    for (int i = 0; i < q; i++) {
        int a, b; scanf("%d %d", &a, &b);
        printf("%d\n", k_num[b] - k_num[a - 1]);
    }
}