#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, k; scanf("%d%d", &n, &k);
    if (n == 1 && k == 0) {
        puts("1");
        return 0;
    }
    if (n < 2 || n > k * 2 + 1) {
        puts("-1");
        return 0;
    }
    int divs = n / 2;
    int kk = k - (divs - 1);
    int cur = kk * 2;
    printf("%d %d ", kk, cur);
    cur++;
    for (int i = 0;i < divs - 1; i++) {
        printf("%d %d ", cur, cur + 1);
        cur += 2;
    }
    if (n & 1)printf("%d", cur);
}