#include <bits/stdc++.h>
using namespace std;
#define ll long long 


int main() {
    int n, k; scanf("%d %d", &n, &k);
    vector<int> p(n + n), t(n + n), sum(n + n);

    for (int i = 1; i <= n;i++) scanf("%d", &p[i]);
    for (int i = 1; i <= n;i++) scanf("%d", &t[i]);

    int tmp = 0, mx = 0;
    for (int i = 1; i <= n; i++) {

        sum[i] = sum[i - 1];
        if (t[i])tmp += p[i];
        else sum[i] += p[i];

        if(i >= k)mx = max(mx, sum[i] - sum[i - k]);
        
    }
    cout << tmp + mx << endl;
}