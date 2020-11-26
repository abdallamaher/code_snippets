#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n, m; scanf("%d%d", &n, &m);
    int time2 = 2 * n;
    int time3 = 3 * n;
    if(time3 > m)printf("%d\n", n - (m - time2));
    else puts("0");

    /*

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int a = 0; a <= n; a++) {
                for (int b = 0; b <= n; b++) {
                    if (i + j + a + b == n && i * 2 + j * 3 + a * 4 + b * 5 == m) {
                        return printf("%d\n", i) * 0;
                    }
                }
            }
        }
    }

    */
    return 0;
}