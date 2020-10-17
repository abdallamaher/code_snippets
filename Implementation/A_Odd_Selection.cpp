#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int t; cin >> t;
    while (t--) {
        int n, s; scanf("%d %d", &n, &s);
        vector<int> v(n);
        int odd = 0, even = 0;
        for (auto& it : v) {
            scanf("%d", &it);
            if (it & 1)odd++;
            else even++;
        }
        even = min(even, s - 1);
        odd = min(odd, s);
        if (odd & 1 ^ 1)odd--;
        puts(odd + even >= s ? "Yes" : "No");
    }
    return 0;
}