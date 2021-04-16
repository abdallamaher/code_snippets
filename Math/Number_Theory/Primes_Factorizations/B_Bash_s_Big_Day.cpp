#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


int main() {
    int n; cin >> n;
    int N = 1e5 + 5;
    vector<int> v(N), vis(N);
    for (int i = 0; i < n;i++) {
        int x; scanf("%d", &x);
        v[x]++;
    }
    int mx = 1;
    for (int i = 2; i <= N; i++) {
        int cnt = 0;
        if (!vis[i]) {
            for (int j = i; j < N; j += i) {
                cnt += v[j];
                vis[j]++;
            }
        }
        mx = max(mx, cnt);
    }
    cout << mx;
}