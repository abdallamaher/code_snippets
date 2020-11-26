#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


int main() {
    int t; cin >> t;
    while (t--) {
        int n; scanf("%d", &n);
        vector<int> e, o;
        for (int i = 1;i <= n * 2; i++) {
            int x; scanf("%d", &x);
            if (x & 1)o.push_back(i);
            else e.push_back(i);
        }
        --n;
        for (int i = 1; i < o.size() && n--; i += 2) {
            printf("%d %d\n", o[i], o[i - 1]);
        }
        for (int i = 1; i < e.size() && n--; i += 2) {
            printf("%d %d\n", e[i], e[i - 1]);
        }
        cout << endl;
    }
    return 0;
}