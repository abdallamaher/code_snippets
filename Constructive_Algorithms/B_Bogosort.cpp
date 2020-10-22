#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int t; cin >> t;
    while (t--) {
        int n; scanf("%d", &n);
        vector<int> ar(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ar[i]);
        }
        sort(ar.rbegin(), ar.rend());
        for (auto it : ar)printf("%d ", it);
        puts("");
    }

    return 0;
}