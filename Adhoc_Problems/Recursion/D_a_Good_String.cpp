#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n; string s;

int getSum(int l, int r, char c) {
    int res = 0;
    for (int i = l; i <= r; i++) if (c != s[i]) res++;
    return res;
}

int solve(int l, int r, char c) {
    if (l == r) {
        if (c == s[l]) return 0;
        else return 1;
    }
    int mid = (l + r) / 2;
    int a = getSum(l, mid, c) + solve(mid + 1, r, c + 1);
    int b = getSum(mid + 1, r, c) + solve(l, mid, c + 1);
    return min(a, b);
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> s;
        s = '#' + s;
        cout << solve(1, n, 'a') << endl;
    }
}