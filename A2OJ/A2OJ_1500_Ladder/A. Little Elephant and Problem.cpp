#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
int ar[N], b[N];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ar[i] = x;
        b[i] = x;
    }
    sort(b, b + n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (ar[i] != b[i])cnt++;
    }
    if (cnt > 2)cout << "NO";
    else cout << "YES";
    return 0;
}

