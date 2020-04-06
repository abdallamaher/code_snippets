#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int n, m, ans;
int p[N];
int main() {
    cin.sync_with_stdio(false);
    cin >> m;
    int cnt = 1 << 20;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        if (x < cnt) cnt = x;
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    sort(p+1, p + n+1, [](int a, int b) {
        return a > b; });
    for (int i = 1; i <= n; i++) {
        p[i] += p[i - 1];
    }

    for (int i = 1; i <= n; ) {
        if (cnt + i <= n) {
            ans += p[cnt + i - 1] - p[i - 1];
            if (cnt + i + 1 <= n) {
                i += cnt + 2;
            }
            else if(cnt + i <= n) {
                i += cnt + 1;
            }
            else {
                break;
            }
        }
        else {
            ans += p[n] - p[i - 1];
            break;
        }
    }
    cout << ans;
    return 0;
}

/*
3
2 3 4
7
20 50 100 100 200 200 200
-----
320
*/