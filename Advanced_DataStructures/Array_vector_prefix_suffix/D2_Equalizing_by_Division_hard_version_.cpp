#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, k;
const int N = 2e5 + 5;
int ar[N];
vector<int> v[N];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", ar + i);
    }
    for (int i = 0; i < n; i++) {
        int x = ar[i];
        int y = 0;
        while (x > 0) {
            v[x].push_back(y);
            x /= 2;
            y++;
        }
    }
    int ans = 1e9;
    for (int i = 0; i < N; i++) {
        if (v[i].size() < k)continue;
        sort(v[i].begin(), v[i].end());
        int cur = 0;
        for (int j = 0; j < k;j++) {
            cur += v[i][j];
        }
        ans = min(cur, ans);
    }
    cout << ans << endl;
}