#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;

int n, m, c;
int A[N], B[N], sum[N];

int main() {
    scanf("%d %d %d", &n, &m, &c);

    for (int i = 1; i <= n; i++) scanf("%d", A + i);
    for (int i = 1; i <= m; i++) {
        scanf("%d", B + i);
        sum[i] = sum[i - 1] + B[i];
    }


    for (int i = 1; i <= n; i++) {
        A[i] += sum[min(i, m)] - sum[max(0, i - n + m - 1)];
        printf("%d ", A[i] % c);
    }

}