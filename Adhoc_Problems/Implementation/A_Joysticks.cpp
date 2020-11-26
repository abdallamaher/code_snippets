#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n, m; scanf("%d %d", &n, &m);
    if (m > n)swap(n, m);
    int ans = 0;
    
    while (n > 1 && m >= 1) {
        n -= 2;
        m++;
        ans++;
        if (m > n)swap(n, m);
    }

    printf("%d\n", ans);
    return 0;
}