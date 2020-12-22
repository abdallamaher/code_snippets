#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    vector<int> data(n + n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &data[i]);
    }
    int l = 1, r = n;
    while (data[l] == l)l++;
    while (data[r] == r)r--;

    int nt = 0;
    for (int i = l;i <= r; i++) {
        int j = i;
        while (data[j] != j && j <= r)j++;
        if (j != i)nt++;
        i = j;
    }
    if (nt == 0)cout << 0 << endl;
    else if (nt == 1)cout << 1 << endl;
    else cout << 2 << endl;
}

int main() {
    int t; cin >> t;
    while (t--)solve();
}