#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
int n;
int ar[N];

inline bool can(int x) {
    for (int i = 1; i <= n; i++) {
        if ((i + (1ll * x * n)) - ar[i] > 0)return 1;
    }
    return 0;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }

    int mn = *min_element(ar, ar + n);
    mn = (mn / n) * n;  // cycle * n

    for (int i = 0; i < n; i++) {
        ar[i] -= mn;
    }
    for (int i = 0; ; i++) {
        if (ar[(i % n)] <= i)return cout << (i % n) + 1, 0;
    }

    return 0;
    int st = 0, en = 1e9, mid;
    while (st < en) {
        mid = (st + en) >> 1;
        if (can(mid)) en = mid;
        else st = mid + 1;
    }
    for (int i = 1; i <= n; i++) {
        if (i + (1ll * en * n) - ar[i] > 0)return cout << i << endl, 0;
    }
    return 0;
}