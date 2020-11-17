#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int ar[1000];
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        ar[x] = i;
    }
    for (int i = 1; i <= n; i++) {
        cout << ar[i] << ' ';
    }
    return 0;
}