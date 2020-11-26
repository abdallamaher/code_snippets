#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n; scanf("%d", &n);
    int ar[5] = {};
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        ar[x]++;
    }
    int x = min(ar[1], ar[3]);
    int sum = ar[4] + x;
    ar[1] -= x, ar[3] -= x;
    sum += ar[3];

    sum += ar[2] / 2;
    ar[2] = ar[2] & 1;

    sum += (ar[1] + 2 * ar[2] + 3) / 4;
    printf("%d\n", sum);
    return 0;
}