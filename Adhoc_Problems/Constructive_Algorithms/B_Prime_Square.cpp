#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
vector<int> p;
const int N = (int)1e5 + 5;
int vis[N];
void seive() {
    for (int i = 2; i * i < N; i++) {
        if (vis[i])continue;
        p.push_back(i);
        for (int j = i;j < N; j += i)
            vis[j] = 1;
    }
}
int main() {
    seive();
    int t; cin >> t;
    while (t--) {
        int n; scanf("%d", &n);
        for (int i = 0;i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)cout << "1 ";
                else if (j == i + 1)cout << "1 ";
                else if (i == n - 1 && !j)cout << "1 ";
                else cout << "0 ";
            }
            cout << '\n';
        }

        continue;
        int x = lower_bound(p.begin(), p.end(), n) - p.begin();
        for (int i = x; i < p.size(); i++) {
            x = p[i] - n + 1;
            if (count(p.begin(), p.end(), x) == 0)break;
        }

        for (int i = 0;i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)cout << x << ' ';
                else cout << 1 << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}