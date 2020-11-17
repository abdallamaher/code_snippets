#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int n, q;
ll ar[N];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        //if (ar[i - 1] > ar[i])ar[i] = ar[i - 1];
        //printf("%d%s", ar[i], i == n ? "\n" : " ");
    }
    cin >> q;
    while (q--) {
        int w, h; 
        cin >> w >> h;
        ll mx = max(ar[1], ar[w]);
        cout << mx << '\n';
        ar[1] = mx + h;
    }
    return 0;
}