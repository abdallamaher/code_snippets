#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n, p1, p2, p3, t1, t2;
    scanf("%d%d%d%d%d%d", &n, &p1, &p2, &p3, &t1, &t2);
    int st = 0, en = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        int l, r; scanf("%d%d", &l, &r);
        sum += (r - l) * p1;
        if (i) {
            sum += min(l - en, t1) * p1;
            if (l - en - t1 > 0)sum += min(l - en - t1, t2) * p2;
            if (l - en - t1 - t2 > 0)sum += (l - en - t1 - t2) * p3;
            
        }
        st = l, en = r;
    }

    printf("%d\n", sum);
    return 0;
}