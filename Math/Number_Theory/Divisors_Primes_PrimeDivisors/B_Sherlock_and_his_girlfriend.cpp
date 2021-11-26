#include <bits/stdc++.h>
using namespace std;
#define ll long long 


int main() {
    int n; cin >> n;
    n++;
    vector<int> vis(n + n, 1);

    for (int i = 2; i * i <= n; i++) {
        if (vis[i] == 1) {
            for (int j = i + i; j <= n; j += i) {
                vis[j] = 2;
            }
        }
    }

    printf("%d\n", n-1 <= 2 ? 1 : 2);
    for (int i = 2;i <= n; i++) {
        printf("%d ", vis[i]);
    }
    return 0;
}