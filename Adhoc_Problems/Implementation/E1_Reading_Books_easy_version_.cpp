#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, k; scanf("%d %d", &n, &k);
    vector<int> both, A, B;
    for (int i = 0; i < n; i++) {
        int t, a, b; scanf("%d %d %d", &t, &a, &b);
        if (a && b)both.push_back(t);
        else if (a)A.push_back(t);
        else if (b)B.push_back(t);
    }
    sort(both.begin(), both.end());
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int ans = 0;
    for (int a = 0, b = 0, bth = 0; k; k--) {
        int ok = 0;
        if (bth < both.size() &&
            (
                (a < A.size() && b < B.size() && both[bth] < A[a] + B[b]) ||
                (a >= A.size() || b >= B.size())
                )
            ) ans += both[bth], bth++, ok = 1;

        else if (a < A.size() && b < B.size())
            ans += A[a] + B[b], a++, b++, ok = 1;

        if (ok == 0)return cout << -1, 0;
    }
    cout << ans << endl;
}