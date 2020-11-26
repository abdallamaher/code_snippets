#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    for (int i = 1; i < n - 1; i++) {
        if (v[i - 1] < v[i] && v[i] > v[i + 1]) {
            printf("YES\n%d %d %d\n", i, i + 1, i + 2);
            return;
        }
    }
    puts("NO");


    return;
    int fr = 0, se = 0;
    for (int i = 1; i < n; i++) {
        if (!se && v[i] < v[fr])fr = i;
        else if (se && v[i] < v[se]) {
            printf("YES\n%d %d %d\n", fr + 1, se + 1, i + 1);
            return;
        }
        else if (v[i] > v[fr]) {
            se = i;
        }
    }
    puts("NO");
}


int main() {
    int t; cin >> t;
    while (t--)solve();
    return 0;
}